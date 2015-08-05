#ifndef __JSScrollViewDelegate_H__
#define __JSScrollViewDelegate_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

NS_CC_EXT_BEGIN

class CC_DLL JSScrollViewDelegate: public CCObject, public CCScrollViewDelegate
{
public:
    JSScrollViewDelegate();
    ~JSScrollViewDelegate();

    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    void setJSDelegate(CCObject* pJSDelegate);

private:
    CCObject* mObj;
};

NS_CC_EXT_END

#endif // __JSScrollViewDelegate_H__
