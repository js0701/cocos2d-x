#include "cocos2d.h"
#include "cocos-ext.h"
#include "script_support/CCScriptSupport.h"
#include "JSTouchDelegate.h"

NS_CC_BEGIN

JSTouchDelegate::TouchDelegateMap JSTouchDelegate::sTouchDelegateMap;

void JSTouchDelegate::setDelegateForJSObject(CCNode* pJSObj, JSTouchDelegate* pDelegate)
{
    sTouchDelegateMap.insert(TouchDelegatePair(pJSObj, pDelegate));
}

JSTouchDelegate* JSTouchDelegate::getDelegateForJSObject(CCNode* pJSObj)
{
    JSTouchDelegate* pRet = NULL;
    TouchDelegateMap::iterator iter = sTouchDelegateMap.find(pJSObj);
    if (iter != sTouchDelegateMap.end())
    {
        pRet = iter->second;
    }
    return pRet;
}

void JSTouchDelegate::removeDelegateForJSObject(CCNode* pJSObj)
{
    TouchDelegateMap::iterator iter = sTouchDelegateMap.find(pJSObj);
    sTouchDelegateMap.erase(pJSObj);
}

void JSTouchDelegate::setJSObject(CCNode *obj) {
    _mObj = obj;
}

void JSTouchDelegate::registerStandardDelegate(CCNode *obj, int priority) {
    JSTouchDelegate *touch = new JSTouchDelegate();
    touch->autorelease();
    cocos2d::CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addStandardDelegate(touch,priority);
    touch->setJSObject(obj);
    JSTouchDelegate::setDelegateForJSObject(obj, touch);
}                                                        
    
void JSTouchDelegate::registerTargetedDelegate(CCNode *obj, int priority, bool swallowsTouches) {
    JSTouchDelegate *touch = new JSTouchDelegate();
    touch->autorelease();
    cocos2d::CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(touch, priority, swallowsTouches);
    touch->setJSObject(obj);
    JSTouchDelegate::setDelegateForJSObject(obj, touch);
}
 
void JSTouchDelegate::unregisterTouchDelegate(CCNode *obj) {  
    JSTouchDelegate* pDelegate = JSTouchDelegate::getDelegateForJSObject(obj);
    if (pDelegate)
    {
        cocos2d::CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(pDelegate);
        JSTouchDelegate::removeDelegateForJSObject(obj);
    } 
}   

bool JSTouchDelegate::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    bool result;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchEvent(cocos2d::CCTOUCHBEGAN, pTouch, result, _mObj);
    return result;
};  
    
void JSTouchDelegate::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchEvent(cocos2d::CCTOUCHMOVED, pTouch, _mObj);
}   

void JSTouchDelegate::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchEvent(cocos2d::CCTOUCHENDED, pTouch, _mObj);
}
    
void JSTouchDelegate::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchEvent(cocos2d::CCTOUCHCANCELLED, pTouch, _mObj);
}   
    
void JSTouchDelegate::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchesEvent(cocos2d::CCTOUCHBEGAN, pTouches, _mObj);
}   

void JSTouchDelegate::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchesEvent(cocos2d::CCTOUCHMOVED, pTouches, _mObj);
}
void JSTouchDelegate::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchesEvent(cocos2d::CCTOUCHENDED, pTouches, _mObj);
}   

void JSTouchDelegate::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent) {
    CC_UNUSED_PARAM(pEvent);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeCustomTouchesEvent(cocos2d::CCTOUCHCANCELLED, pTouches, _mObj);
} 

NS_CC_END
