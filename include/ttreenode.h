#ifndef __TTREENODE_H__
#define __TTREENODE_H__

#include "defines.h"

#include "ttabrecord.h"

class TTreeNode: public TTabRecord {
  public:
    TTreeNode(TKey k = "", PTDatValue pVal = nullptr, PTTreeNode pL = nullptr,
            PTTreeNode pR = nullptr): TTabRecord(k,pVal), pLeft(pL), pRight(pR) {};
    PTTreeNode GetLeft(); 
    PTTreeNode GetRight(); 
    virtual PTDatValue GetCopy();  

  protected:
    PTTreeNode pLeft, pRight; 

    friend class TTreeTable;
    friend class TBalanceTree;
};

#endif 
