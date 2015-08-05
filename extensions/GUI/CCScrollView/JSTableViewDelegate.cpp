#include "cocos2d.h"
#include "cocos-ext.h"
#include "script_support/CCScriptSupport.h"
#include "JSTableViewDelegate.h"

NS_CC_EXT_BEGIN

JSTableViewDelegate::JSTableViewDelegate() {

}

JSTableViewDelegate::~JSTableViewDelegate() {

}

void JSTableViewDelegate::scrollViewDidScroll(CCScrollView* view) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeScrollDidScroll(mObj);
}

void JSTableViewDelegate::scrollViewDidZoom(CCScrollView* view) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeScrollDidZoom(mObj);
}

void JSTableViewDelegate::tableCellTouched(CCTableView* table, CCTableViewCell* cell) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellTouched(mObj, cell);
}

void JSTableViewDelegate::tableCellHighlight(CCTableView* table, CCTableViewCell* cell) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellHighlight(mObj, cell);
}

void JSTableViewDelegate::tableCellUnhighlight(CCTableView* table, CCTableViewCell* cell) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellUnhighlight(mObj, cell);
}

void JSTableViewDelegate::tableCellWillRecycle(CCTableView* table, CCTableViewCell* cell) {
    if (mObj == NULL) return;
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellWillRecycle(mObj, cell);
}

void JSTableViewDelegate::setJSDelegate(CCObject* pJSDelegate) {
    mObj = pJSDelegate;
}

NS_CC_EXT_END
