#include "cocos2d.h"
#include "cocos-ext.h"
#include "script_support/CCScriptSupport.h"
#include "JSScrollViewDelegate.h"

NS_CC_EXT_BEGIN

JSScrollViewDelegate::JSScrollViewDelegate() {

}

JSScrollViewDelegate::~JSScrollViewDelegate() {

}

void JSScrollViewDelegate::scrollViewDidScroll(CCScrollView* view) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeScrollDidScroll(mObj);
}

void JSScrollViewDelegate::scrollViewDidZoom(CCScrollView* view) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeScrollDidZoom(mObj);
}

void JSScrollViewDelegate::setJSDelegate(CCObject* pJSDelegate) {
    mObj = pJSDelegate;
}

NS_CC_EXT_END
