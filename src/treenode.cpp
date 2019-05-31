#include "treenode.h"

TTreeNode::TTreeNode(TKey k, PTDatValue pVal, PTTreeNode pL, PTTreeNode pR) : TTabRecord(k, pVal) {
    pLeft = pL;
    pRight = pR;
}

PTDatValue TTreeNode::GetCopy() const {
    PTTreeNode pL = nullptr;
    PTTreeNode pR = nullptr;

    if (pLeft != nullptr) {
        pL = (PTTreeNode)pLeft->GetCopy();
    }
    if (pRight != nullptr) {
        pR = (PTTreeNode)pRight->GetCopy();
    }

    return new TTreeNode(key, pValue, pL, pR);
}

PTTreeNode TTreeNode::GetLeft() const {
    return pLeft;
}

PTTreeNode TTreeNode::GetRight() const {
    return pRight;
}
