#ifndef __TOUCH_DELEGATE_JSTOUCH_DELEGATE_H__
#define __TOUCH_DELEGATE_JSTOUCH_DELEGATE_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

NS_CC_BEGIN

class CC_DLL JSTouchDelegate: public CCObject, public CCTouchDelegate
{
public:
    // Set the touch delegate to map by using the key (pJSObj).
    static void setDelegateForJSObject(CCNode* pJSObj, JSTouchDelegate* pDelegate);
    // Get the touch delegate by the key (pJSObj).
    static JSTouchDelegate* getDelegateForJSObject(CCNode* pJSObj);
    // Remove the delegate by the key (pJSObj).
    static void removeDelegateForJSObject(CCNode* pJSObj);

    void setJSObject(CCNode *obj);
    static void registerStandardDelegate(CCNode *obj, int priority);
    static void registerTargetedDelegate(CCNode *obj, int priority, bool swallowsTouches);
    // unregister touch delegate.
    // Normally, developer should invoke cc.unregisterTouchDelegate() in when the scene exits.
    // So this function need to be binded.
    static void unregisterTouchDelegate(CCNode *obj);

    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    // optional
    void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);

private:
    CCNode* _mObj;
    typedef std::map<CCNode*, JSTouchDelegate*> TouchDelegateMap;
    typedef std::pair<CCNode*, JSTouchDelegate*> TouchDelegatePair;
    static TouchDelegateMap sTouchDelegateMap;
};

NS_CC_END

#endif // __TOUCH_DELEGATE_JSTOUCH_DELEGATE_H__
