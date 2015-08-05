#include "cocos2d.h"
#include "cocos-ext.h"
#include "script_support/CCScriptSupport.h"
#include "JSTableViewDataSource.h"

NS_CC_EXT_BEGIN

JSTableViewDataSource::JSTableViewDataSource() {

}

JSTableViewDataSource::~JSTableViewDataSource() {

}

CCSize JSTableViewDataSource::tableCellSizeForIndex(CCTableView *table, unsigned int idx) {
    if (mObj == NULL) return CCSize(0, 0);
    return CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellSizeForIndex(mObj, idx);
}

CCTableViewCell* JSTableViewDataSource::tableCellAtIndex(CCTableView *table, unsigned int idx) {
    if (mObj == NULL) return NULL;
    return CCScriptEngineManager::sharedManager()->getScriptEngine()->executeTableCellAtIndex(mObj, idx);
}

unsigned int JSTableViewDataSource::numberOfCellsInTableView(CCTableView *table) {
    if (mObj == NULL) return 0;
    return CCScriptEngineManager::sharedManager()->getScriptEngine()->executeNumberOfCellsInTableView(mObj);
}

void JSTableViewDataSource::setTableViewDataSource(CCObject* pJSDelegate) {
    mObj = pJSDelegate;
}

NS_CC_EXT_END
