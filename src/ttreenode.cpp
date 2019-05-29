#include "ttreenode.h"

PTDatValue TTreeNode::GetCopy() {
    return new TTreeNode(Key, pValue, nullptr, nullptr);
}
