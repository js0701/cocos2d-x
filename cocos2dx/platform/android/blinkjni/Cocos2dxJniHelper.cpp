/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

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
#include "Cocos2dxJniHelper.h"
#include "CCBitmapDC.h"
//#include "jni_Cocos2dxHelper.h"
#include "base/android/jni_android.h"
#include "base/android/jni_string.h"
#include "base/strings/string_piece.h"

#include "jni/Cocos2dxHelper_jni.h"
#include <android/log.h>
#include <string.h>
#include <string>


#if 1
#define  LOG_TAG    "JniHelper"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...) 
#endif

//using namespace cocos2d;
using namespace std;


namespace cocos2d{

string g_apkPath;
JNIEnv* g_JNIEnv;

bool getEnv(JNIEnv** pEnv)
{
   *pEnv = base::android::AttachCurrentThread();//g_JNIEnv;
   if(*pEnv == NULL)
       return false;
   else
       return true;
}

static string jstring2string_(jstring jstr)
{
    if (jstr == NULL)
    {
        return "";
    }
    
    JNIEnv *env = 0;

    if (!getEnv(&env))
    {
        return 0;
    }

    const char* chars = env->GetStringUTFChars(jstr, NULL);
    string ret(chars);
    env->ReleaseStringUTFChars(jstr, chars);

    return ret;
}

const char * getApkPath() {
    return g_apkPath.c_str();
}

std::string getFileDirectoryJNI() {
    
    std::string ret("");

    JNIEnv *env;
    getEnv(&env);
    
    base::android::ScopedJavaLocalRef<jstring> str = android::Java_Cocos2dxHelper_getCocos2dxWritablePath(env);
    ret = jstring2string_(str.obj());
    
    return ret;
}

//Called by Java
namespace android {
static void SetApkPath(JNIEnv*  env, jclass thiz, jstring apkPath) {
        g_apkPath = cocos2d::jstring2string_(apkPath);
    }
}

bool RegisterCocos2dJni(JNIEnv* env){

  RegisterBitmapDCJni(env); 
  g_JNIEnv = env;
  return android::RegisterNativesImpl(env);
}


}

