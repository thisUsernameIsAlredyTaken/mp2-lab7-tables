#include "tbalancenode.h"

TBalanceNode::TBalanceNode(TKey k, PTDatValue pval,
        PTTreeNode pl, PTTreeNode pr, int bal)
  : TTreeNode(k, pval, pl, pr), Balance(bal) {}
