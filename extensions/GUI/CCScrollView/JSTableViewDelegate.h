#ifndef __JSTableViewDelegate_H__
#define __JSTableViewDelegate_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

NS_CC_EXT_BEGIN

class CC_DLL JSTableViewDelegate: public CCObject, public CCTableViewDelegate
{
public:
    JSTableViewDelegate();
    ~JSTableViewDelegate();

    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual void tableCellHighlight(CCTableView* table, CCTableViewCell* cell);
    virtual void tableCellUnhighlight(CCTableView* table, CCTableViewCell* cell);
    virtual void tableCellWillRecycle(CCTableView* table, CCTableViewCell* cell);
    virtual void setJSDelegate(CCObject* pJSDelegate);

private:
    CCObject* mObj;
};

NS_CC_EXT_END

#endif // __JSTableViewDelegate_H__
