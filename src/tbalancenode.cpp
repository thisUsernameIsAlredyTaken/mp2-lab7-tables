#include "tbalancenode.h"

PTDatValue TBalanceNode::GetCopy() {
    return new TBalanceNode(Key, pValue, nullptr, nullptr, 0);
}

int TBalanceNode::GetBalance() {
    return Balance;
}

void TBalanceNode::SetBalance(int bal) {
    Balance = bal;
}
