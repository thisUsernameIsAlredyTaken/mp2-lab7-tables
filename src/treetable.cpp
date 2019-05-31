#include "treetable.h"

#include "treenode.h"

TTreeTable::TTreeTable() : TTable() {
    currPos = 0;
    pRoot = pCurrent = nullptr;
    ppRef = nullptr;
}

TTreeTable::~TTreeTable() {
    DeleteTreeTab(pRoot);
}

bool TTreeTable::IsFull() const {
    return false;
}

PTDatValue TTreeTable::FindRecord(TKey k) {

}

void TTreeTable::InsRecord(TKey k, PTDatValue pVal) {

}

void TTreeTable::DelRecord(TKey k) {

}

TKey TTreeTable::GetKey() const {
    return pCurrent->GetKey();
}

PTDatValue TTreeTable::GetValuePtr() const {
    return pCurrent->GetValuePtr();
}

bool TTreeTable::Reset() {
    currPos = 0;
    pCurrent = nullptr;

    while (st.size() > 0) {
        st.pop();
    }

    PTTreeNode tmp = pRoot;

    while (tmp != nullptr) {
        st.push(tmp);
        tmp = tmp->GetLeft();
    }

    if (st.size() > 0) {
        pCurrent = st.top();
    }

    return IsTabEnded();
}

bool TTreeTable::IsTabEnded() const {
    return currPos >= dataCount;
}

bool TTreeTable::GoNext() {
    st.pop();
    PTTreeNode p = pCurrent->GetRight();
    while (p) {
        st.push(p);
        p = p->GetLeft();
    }
    if (st.size()) {
        pCurrent = st.top();
    }
    else {
        pCurrent = nullptr;
    }
    ++currPos;
    return IsTabEnded();
}

void TTreeTable::DeleteTreeTab(PTTreeNode) {

}
