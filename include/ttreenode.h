#ifndef __TTREENODE_H__
#define __TTREENODE_H__

#include "defines.h"

#include "ttabrecord.h"

class TTreeNode : public TTabRecord {
  public:
    TTreeNode(TKey k="",
            PTDatValue pval=nullptr,
            PTTreeNode pl=nullptr,
            PTTreeNode pr=nullptr);

    PTTreeNode GetLeft();
    PTTreeNode GetRight();

    PTDatValue GetCopy() override;

  protected:
    PTTreeNode PLeft, PRight;

    friend class TTreeTable;
    friend class TBalanceTree;
};

#endif
