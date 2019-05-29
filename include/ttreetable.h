#ifndef __TTREETABLE_H__
#define __TTREETABLE_H__

#include "defines.h"

#include "ttable.h"
#include "ttreenode.h"

#include <stack>

class TTreeTable : public TTable {
  public:
    TTreeTable();
    ~TTreeTable();

    bool IsFull() override;

    PTDatValue FindRecord(TKey k) override;
    void InsRecord(TKey k, PTDatValue pval) override;
    void DelRecord(TKey k) override;

    void Print(PTTreeNode pNode, int depth=0);
    void Print();

    TKey GetKey() override;
    PTDatValue GetValuePtr() override;

    void Reset() override;
    bool IsTabEnded() override;
    bool GoNext() override;

  protected:
    void DeleteTreeTab(PTTreeNode PNode);

    PTTreeNode PRoot;
    PTTreeNode *PPRef;
    PTTreeNode PCurrent;
    int CurrPos;
    std::stack<PTTreeNode> St;
};




#endif
