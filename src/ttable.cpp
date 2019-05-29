#include "ttable.h"

TTable::TTable()
  : DataCount(0), Efficiency(0) {}

TTable::~TTable() {}

int TTable::GetDataCount() {
    return DataCount;
}

int TTable::GetEfficiency() {
    return Efficiency;
}

void TTable::ResetsEfficiency() {
    Efficiency = 0;
}

bool TTable::IsEmpty() {
    return DataCount == 0;
}

