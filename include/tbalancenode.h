#ifndef __TBALANCENODE_H__
#define __TBALANCENODE_H__

#include "defines.h"

#include "ttreenode.h"

class TBalanceNode : public TTreeNode {
  public:
    TBalanceNode(TKey k="", PTDatValue pval=nullptr,
            PTTreeNode pl=nullptr,
            PTTreeNode pr=nullptr,
            int bal=BalOk);

    PTDatValue GetCopy() override;

    int GetBalance();
    void SetBalance(int bal);

  protected:
    int Balance;

    friend class TBalanceTree;
};

#endif
