#ifndef __TBALANCETREE_H__
#define __TBALANCETREE_H__

#include "defines.h"

#include "ttreetable.h"

class TBalanceTree : public TTreeTable {
  public:
    TBalanceTree();

    void InsRecord(TKey k, PTDatValue pval) override;

  protected:
    int InsBalanceTree(PTTreeNode &pnode,
            TKey k, PTDatValue pval);
    int LeftTreeBalancing(PTBalanceNode &pnode);
    int RightTreeBalancing(PTBalanceNode &pnode);
};

#endif
