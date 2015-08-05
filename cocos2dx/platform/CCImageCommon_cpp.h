/****************************************************************************
Copyright (c) 2010 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CC_PLATFORM_IMAGE_CPP__
#error "CCFileUtilsCommon_cpp.h can only be included for CCFileUtils.cpp in platform/win32(android,...)"
#endif /* __CC_PLATFORM_IMAGE_CPP__ */

#include "CCImage.h"
#include "CCCommon.h"
#include "CCStdC.h"
#include "CCFileUtils.h"
#include "png.h"
//#include "jpeglib.h"
#include "tiffio.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#include "CCFreeTypeFont.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCFileUtilsAndroid.h"
#endif

#include <string>
#include <ctype.h>

#ifdef EMSCRIPTEN
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#endif // EMSCRIPTEN

NS_CC_BEGIN

// premultiply alpha, or the effect will wrong when want to use other pixel format in CCTexture2D,
// such as RGB888, RGB5A1
#define CC_RGB_PREMULTIPLY_ALPHA(vr, vg, vb, va) \
    (unsigned)(((unsigned)((unsigned char)(vr) * ((unsigned char)(va) + 1)) >> 8) | \
    ((unsigned)((unsigned char)(vg) * ((unsigned char)(va) + 1) >> 8) << 8) | \
    ((unsigned)((unsigned char)(vb) * ((unsigned char)(va) + 1) >> 8) << 16) | \
    ((unsigned)(unsigned char)(va) << 24))

// on ios, we should use platform/ios/CCImage_ios.mm instead

typedef struct 
{
    unsigned char* data;
    int size;
    int offset;
}tImageSource;

static void pngReadCallback(png_structp png_ptr, png_bytep data, png_size_t length)
{
    tImageSource* isource = (tImageSource*)png_get_io_ptr(png_ptr);

    if((int)(isource->offset + length) <= isource->size)
    {
        memcpy(data, isource->data+isource->offset, length);
        isource->offset += length;
    }
    else
    {
        png_error(png_ptr, "pngReaderCallback failed");
    }
}

//////////////////////////////////////////////////////////////////////////
// Implement CCImage
//////////////////////////////////////////////////////////////////////////

CCImage::CCImage()
: m_nWidth(0)
, m_nHeight(0)
, m_nBitsPerComponent(0)
, m_pData(0)
, m_bHasAlpha(false)
, m_bPreMulti(false)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    m_ft = nullptr;
#endif
}

CCImage::~CCImage()
{
    CC_SAFE_DELETE_ARRAY(m_pData);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    CC_SAFE_DELETE(m_ft);
#endif
}

bool CCImage::initWithImageFile(const char * strPath, EImageFormat eImgFmt/* = eFmtPng*/)
{
    bool bRet = false;

#ifdef EMSCRIPTEN
    // Emscripten includes a re-implementation of SDL that uses HTML5 canvas
    // operations underneath. Consequently, loading images via IMG_Load (an SDL
    // API) will be a lot faster than running libpng et al as compiled with
    // Emscripten.
    SDL_Surface *iSurf = IMG_Load(strPath);

    int size = 4 * (iSurf->w * iSurf->h);
    bRet = _initWithRawData((void*)iSurf->pixels, size, iSurf->w, iSurf->h, 8, true);

    unsigned int *tmp = (unsigned int *)m_pData;
    int nrPixels = iSurf->w * iSurf->h;
    for(int i = 0; i < nrPixels; i++)
    {
        unsigned char *p = m_pData + i * 4;
        tmp[i] = CC_RGB_PREMULTIPLY_ALPHA( p[0], p[1], p[2], p[3] );
    }

    SDL_FreeSurface(iSurf);
#else
    unsigned long nSize = 0;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(strPath);
    unsigned char* pBuffer = CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rb", &nSize);
    if (pBuffer != NULL && nSize > 0)
    {
        bRet = initWithImageData(pBuffer, nSize, eImgFmt);
    }
    CC_SAFE_DELETE_ARRAY(pBuffer);
#endif // EMSCRIPTEN

    return bRet;
}

bool CCImage::initWithImageFileThreadSafe(const char *fullpath, EImageFormat imageType)
{
    bool bRet = false;
    unsigned long nSize = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCFileUtilsAndroid *fileUitls = (CCFileUtilsAndroid*)CCFileUtils::sharedFileUtils();
    unsigned char *pBuffer = fileUitls->getFileDataForAsync(fullpath, "rb", &nSize);
#else
    unsigned char *pBuffer = CCFileUtils::sharedFileUtils()->getFileData(fullpath, "rb", &nSize);
#endif
    if (pBuffer != NULL && nSize > 0)
    {
        bRet = initWithImageData(pBuffer, nSize, imageType);
    }
    CC_SAFE_DELETE_ARRAY(pBuffer);
    return bRet;
}

bool CCImage::initWithImageData(void * pData, 
                                int nDataLen, 
                                EImageFormat eFmt/* = eSrcFmtPng*/, 
                                int nWidth/* = 0*/,
                                int nHeight/* = 0*/,
                                int nBitsPerComponent/* = 8*/)
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! pData || nDataLen <= 0);

        if (kFmtPng == eFmt)
        {
            //bRet = _initWithPngData(pData, nDataLen);
            break;
        }
        else if (kFmtJpg == eFmt)
        {
            //bRet = _initWithJpgData(pData, nDataLen);
            break;
        }
        else if (kFmtTiff == eFmt)
        {
            //bRet = _initWithTiffData(pData, nDataLen);
            break;
        }
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
       else if (kFmtWebp == eFmt)
        {
            bRet = _initWithWebpData(pData, nDataLen);
            break;
        }
#endif
        else if (kFmtRawData == eFmt)
        {
            bRet = _initWithRawData(pData, nDataLen, nWidth, nHeight, nBitsPerComponent, false);
            break;
        }
        else
        {
            // if it is a png file buffer.
            if (nDataLen > 8)
            {
                unsigned char* pHead = (unsigned char*)pData;
                if (   pHead[0] == 0x89
                    && pHead[1] == 0x50
                    && pHead[2] == 0x4E
                    && pHead[3] == 0x47
                    && pHead[4] == 0x0D
                    && pHead[5] == 0x0A
                    && pHead[6] == 0x1A
                    && pHead[7] == 0x0A)
                {
                    //bRet = _initWithPngData(pData, nDataLen);
                    break;
                }
            }

            // if it is a tiff file buffer.
            if (nDataLen > 2)
            {
                unsigned char* pHead = (unsigned char*)pData;
                if (  (pHead[0] == 0x49 && pHead[1] == 0x49)
                    || (pHead[0] == 0x4d && pHead[1] == 0x4d)
                    )
                {
                    //bRet = _initWithTiffData(pData, nDataLen);
                    break;
                }
            }

            // if it is a jpeg file buffer.
            if (nDataLen > 2)
            {
                unsigned char* pHead = (unsigned char*)pData;
                if (   pHead[0] == 0xff
                    && pHead[1] == 0xd8)
                {
                    //bRet = _initWithJpgData(pData, nDataLen);
                    break;
                }
            }
        }
    } while (0);
    return bRet;
}

/*
 * ERROR HANDLING:
 *
 * The JPEG library's standard error handler (jerror.c) is divided into
 * several "methods" which you can override individually.  This lets you
 * adjust the behavior without duplicating a lot of code, which you might
 * have to update with each future release.
 *
 * We override the "error_exit" method so that control is returned to the
 * library's caller when a fatal error occurs, rather than calling exit()
 * as the standard error_exit method does.
 *
 * We use C's setjmp/longjmp facility to return control.  This means that the
 * routine which calls the JPEG library must first execute a setjmp() call to
 * establish the return point.  We want the replacement error_exit to do a
 * longjmp().  But we need to make the setjmp buffer accessible to the
 * error_exit routine.  To do this, we make a private extension of the
 * standard JPEG error handler object.  (If we were using C++, we'd say we
 * were making a subclass of the regular error handler.)
 *
 * Here's the extended error handler struct:
 */

struct my_error_mgr {
  //struct jpeg_error_mgr pub;	/* "public" fields */

  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr * my_error_ptr;

/*
 * Here's the routine that will replace the standard error_exit method:
 */


bool CCImage::_initWithRawData(void * pData, int nDatalen, int nWidth, int nHeight, int nBitsPerComponent, bool bPreMulti)
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(0 == nWidth || 0 == nHeight);

        m_nBitsPerComponent = nBitsPerComponent;
        m_nHeight   = (short)nHeight;
        m_nWidth    = (short)nWidth;
        m_bHasAlpha = true;
        m_bPreMulti = bPreMulti;

        // only RGBA8888 supported
        int nBytesPerComponent = 4;
        int nSize = nHeight * nWidth * nBytesPerComponent;
        m_pData = new unsigned char[nSize];
        CC_BREAK_IF(! m_pData);
        memcpy(m_pData, pData, nSize);

        bRet = true;
    } while (0);

    return bRet;
}

bool CCImage::saveToFile(const char *pszFilePath, bool bIsToRGB)
{
    bool bRet = false;

    do 
    {
        CC_BREAK_IF(NULL == pszFilePath);

        std::string strFilePath(pszFilePath);
        CC_BREAK_IF(strFilePath.size() <= 4);

        std::string strLowerCasePath(strFilePath);
        for (unsigned int i = 0; i < strLowerCasePath.length(); ++i)
        {
            strLowerCasePath[i] = tolower(strFilePath[i]);
        }

        if (std::string::npos != strLowerCasePath.find(".png"))
        {
            break;//CC_BREAK_IF(!_saveImageToPNG(pszFilePath, bIsToRGB));
        }
        else if (std::string::npos != strLowerCasePath.find(".jpg"))
        {
            //CC_BREAK_IF(!_saveImageToJPG(pszFilePath));
        }
        else
        {
            break;
        }

        bRet = true;
    } while (0);

    return bRet;
}

NS_CC_END

