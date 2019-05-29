#include "ttreenode.h"

TTreeNode::TTreeNode(TKey k, PTDatValue pval,
        PTTreeNode pl, PTTreeNode pr)
  : TTabRecord(k, pval), PLeft(pl), PRight(pr) {}


