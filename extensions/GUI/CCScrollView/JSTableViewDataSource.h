#ifndef __JSTableViewDataSource_H__
#define __JSTableViewDataSource_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

NS_CC_EXT_BEGIN

class CC_DLL JSTableViewDataSource: public CCObject, public CCTableViewDataSource
{
public:
    JSTableViewDataSource();
    ~JSTableViewDataSource();

    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);

    void setTableViewDataSource(CCObject* pJSSource);
private:
    CCObject* mObj;
};

NS_CC_EXT_END

#endif // __JSTableViewDataSource_H__
