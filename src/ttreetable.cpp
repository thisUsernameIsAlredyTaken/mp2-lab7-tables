#include "ttreetable.h"

TTreeTable::TTreeTable()
  : TTable(), CurrPos(0), PRoot(nullptr),
    PCurrent(nullptr), PPRef(nullptr) {}

TTreeTable::~TTreeTable() {
    DeleteTreeTab(PRoot);
}

void TTreeTable::Print() {
    Print(PRoot);
}
