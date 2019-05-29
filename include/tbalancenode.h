#ifndef __TBALANCENODE_H__
#define __TBALANCENODE_H__

#include "defines.h"

#include "ttreenode.h"

class TBalanceNode : public TTreeNode {
  public:
    TBalanceNode (TKey k = "", PTDatValue pVal = nullptr,
            PTTreeNode pL = nullptr, PTTreeNode pR = nullptr, int bal = BalOk):
            TTreeNode(k, pVal, pL, pR), Balance(bal) {}; 
    virtual PTDatValue GetCopy();  
    int GetBalance();
    void SetBalance(int bal);

  protected:
    int Balance; 
    
    friend class TBalanceTree;
};

#endif 
