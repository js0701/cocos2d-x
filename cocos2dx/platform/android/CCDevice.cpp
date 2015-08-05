#include "platform/CCDevice.h"
#include "jni/DPIJni.h"

NS_CC_BEGIN

int CCDevice::getDPI()
{
    static int dpi = -1;
    if (dpi == -1)
    {
        // TODO: Get dpi by JNI.
        dpi = 400;
    }
    return dpi;
}

NS_CC_END
