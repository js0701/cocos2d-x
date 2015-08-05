#ifndef COCOS2D_BITMAPDC__ON_ANDROID_BITMAP_H_
#define COCOS2D_BITMAPDC__ON_ANDROID_BITMAP_H_

#include <jni.h>
#include <string.h>

//#include <unicode/uchar.h>
//#include <unicode/uscript.h>

#include "base/android/jni_android.h"
#include "base/strings/string16.h"
#include "base/strings/string_piece.h"

using base::android::ScopedJavaLocalRef;

namespace cocos2d {

class BitmapDC
{
public:
     BitmapDC();
     ~BitmapDC();
     static BitmapDC& sharedBitmapDC();
     bool getBitmapFromJavaShadowStroke(	const char *text,
                                        int nWidth,
                                        int nHeight,
                                        int eAlignMask,
                                        const char * pFontPathName,
                                        float fontSize,
                                        float textTintR 		= 1.0,
                                        float textTintG 		= 1.0,
                                        float textTintB 		= 1.0,
                                        bool shadow             = false,
                                        float shadowDeltaX 		= 0.0,
                                        float shadowDeltaY 		= 0.0,
                                        float shadowBlur 		= 0.0,
                                        float shadowIntensity 	= 0.0,
                                        bool stroke 			= false,
                                        float strokeColorR 		= 0.0,
                                        float strokeColorG 		= 0.0,
                                        float strokeColorB 		= 0.0,
                                        float strokeSize 		= 0.0 );
      bool getBitmapFromJava(const char *text, int nWidth, int nHeight, int eAlignMask, const char * pFontName, float fontSize);
      unsigned int swapAlpha(unsigned int value);

public:
    int m_nWidth;
    int m_nHeight;
    unsigned char *m_pData;
    JNIEnv *env;
};


bool RegisterBitmapDCJni(JNIEnv* env);

}

#endif


