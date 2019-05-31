#include "treetable.h"

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

}

PTDatValue TTreeTable::GetValuePtr() const {

}

bool TTreeTable::Reset() {

}

bool TTreeTable::IsTabEnded() const {

}

bool TTreeTable::GoNext() {

}

void TTreeTable::DeleteTreeTab(PTTreeNode) {

}
