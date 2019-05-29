#ifndef __TBALANCETREE_H__
#define __TBALANCETREE_H__

#include "defines.h"

#include "tbalancenode.h"
#include "ttreetable.h"

class TBalanceTree : public TTreeTable {
  public:
    TBalanceTree() : TTreeTable() {} 
    
    virtual void InsRecord(TKey k, PTDatValue pVal); 

  protected:
    int InsBalanceTree(PTTreeNode &pNode_, TKey k, PTDatValue pVal);
    int LeftTreeBalancing(PTBalanceNode &pNode); 
    int RightTreeBalancing(PTBalanceNode &pNode);
};

#endif 
