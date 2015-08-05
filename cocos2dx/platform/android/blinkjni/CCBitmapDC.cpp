
#include "CCBitmapDC.h"

#include "base/android/jni_android.h"
#include "base/android/jni_string.h"
#include "base/strings/string_piece.h"

#include "jni/Cocos2dxBitmapDC_jni.h"

using namespace base::android;

namespace cocos2d {

    static BitmapDC s_BmpDC;

    BitmapDC:: BitmapDC()
    : m_nWidth(0)
    , m_nHeight(0)
    , m_pData(NULL)
    {
    }

    BitmapDC:: ~BitmapDC(void)
    {
        if (m_pData)
        {
            delete [] m_pData;
        }
    }

   bool BitmapDC:: getBitmapFromJavaShadowStroke(	const char *text,
                                        int nWidth,
                                        int nHeight,
                                        int eAlignMask,
                                        const char * pFontPathName,
                                        float fontSize,
                                        float textTintR,
                                        float textTintG,
                                        float textTintB,
                                        bool shadow,
                                        float shadowDeltaX,
                                        float shadowDeltaY,
                                        float shadowBlur,
                                        float shadowIntensity,
                                        bool stroke,
                                        float strokeColorR,
                                        float strokeColorG,
                                        float strokeColorB,
                                        float strokeSize)
    {
           // Do a full lookup for the font path using CCFileUtils in case the given font name is a relative path to a font file asset,
           // or the path has been mapped to a different location in the app package:
           std::string fullPathOrFontName(pFontPathName); //= CCFileUtils::sharedFileUtils()->fullPathForFilename(pFontName);
           env = AttachCurrentThread();

		   // If the path name returned includes the 'assets' dir then that needs to be removed, because the android.content.Context
		   // requires this portion of the path to be omitted for assets inside the app package.
		   if (fullPathOrFontName.find("assets/") == 0)
		   {
               fullPathOrFontName = fullPathOrFontName.substr(strlen("assets/")); // Chop out the 'assets/' portion of the path.
           }

           /**create bitmap
                   * this method call Cococs2dx.createBitmap()(java code) to create the bitmap, the java code
                   * will call Java_org_cocos2dx_lib_Cocos2dxBitmap_nativeInitBitmapDC() to init the width, height
                   * and data.
                   * use this approach to decrease the jni call number
                */
           ScopedJavaLocalRef<jstring> jstrText = ConvertUTF8ToJavaString(
                                                  env, text);
           ScopedJavaLocalRef<jstring> jstrFont = ConvertUTF8ToJavaString(
                                                  env, fullPathOrFontName.c_str());

           android::Java_Cocos2dxBitmapDC_createTextBitmapShadowStroke(env, jstrText.obj(),
               jstrFont.obj(), (int)fontSize, textTintR, textTintG, textTintB, eAlignMask, nWidth, nHeight, shadow, shadowDeltaX, -shadowDeltaY, shadowBlur, stroke, strokeColorR, strokeColorG, strokeColorB, strokeSize);

           return true;
    }


    bool BitmapDC:: getBitmapFromJava(const char *text, int nWidth, int nHeight, int eAlignMask, const char * pFontName, float fontSize)
    {
    	return  getBitmapFromJavaShadowStroke(	text, nWidth, nHeight, eAlignMask, pFontName, fontSize );
    }

    // ARGB -> RGBA
    inline unsigned int BitmapDC:: swapAlpha(unsigned int value)
    {
        return ((value << 8 & 0xffffff00) | (value >> 24 & 0x000000ff));
    }

    BitmapDC& BitmapDC:: sharedBitmapDC()
    {
    return s_BmpDC;
    }

    /**
    * this method is called by java code to init width, height and pixels data
    */
    namespace android{

    static void InitBitmapDC(JNIEnv*  env, jclass thiz, int width, int height, jbyteArray pixels)
    {
        int size = width * height * 4;
        BitmapDC& bitmapDC = BitmapDC::sharedBitmapDC();
        bitmapDC.m_nWidth = width;
        bitmapDC.m_nHeight = height;
        bitmapDC.m_pData = new unsigned char[size];
        env->GetByteArrayRegion(pixels, 0, size, (jbyte*)bitmapDC.m_pData);

        // swap data
        unsigned int *tempPtr = (unsigned int*)bitmapDC.m_pData;
        unsigned int tempdata = 0;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                tempdata = *tempPtr;
                *tempPtr++ = bitmapDC.swapAlpha(tempdata);
            }
        }
    }

   }

   bool RegisterBitmapDCJni(JNIEnv* env){
        return android::RegisterNativesImpl(env);
   }

}

