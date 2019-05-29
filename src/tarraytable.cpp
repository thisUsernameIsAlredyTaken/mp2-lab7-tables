#include "tarraytable.h"

TArrayTable::~TArrayTable() {}

TArrayTable::TArrayTable(int size) {
    PRecs = new PTTabRecord[size];
    for (int i = 0; i < size; ++i) {
        PRecs[i] = nullptr;
    }
    TabSize = size;
    DataCount = 0;
    CurrPos = 0;
}

bool TArrayTable::IsFull() {
    return DataCount >= TabSize;
}

int TArrayTable::GetTabSize() {
    return TabSize;
}

TKey TArrayTable::GetKey(TDataPos mode) {
    int pos = -1;
    if (!IsEmpty()) {
        switch (mode) {
          case FIRST_POS:
            pos = 0;
            break;
          case LAST_POS:
            pos = DataCount - 1;
            break;
          case CURRENT_POS:
          default:
            pos = CurrPos;
            break;
        }
    }
    if (pos == -1) {
        return "";
    } else {
        return PRecs[pos]->Key;
    }
}

PTDatValue TArrayTable::GetValuePtr() {
    return GetDatValuePtr(CURRENT_POS);
}

PTDatValue TArrayTable::GetDatValuePtr(TDataPos mode) {
    int pos = -1;
    if (!IsEmpty()) {
        switch (mode) {
          case FIRST_POS:
            pos = 0;
            break;
          case LAST_POS:
            pos = DataCount - 1;
            break;
          case CURRENT_POS:
          default:
            pos = CurrPos;
            break;
        }
    }
    if (pos == -1) {
        return nullptr;
    } else {
        return PRecs[pos]->PValue;
    }
}

void TArrayTable::Reset() {
    CurrPos = 0;
}

bool TArrayTable::IsTabEnded() {
    return CurrPos >= DataCount;
}

bool TArrayTable::GoNext() {
    if (!IsTabEnded()) {
        ++CurrPos;
    }
    return IsTabEnded();
}

void TArrayTable::SetCurrentPos(int pos) {
    if (pos >= 0 && pos < DataCount) {
        CurrPos = pos;
    } else {
        CurrPos = 0;
    }
}

int TArrayTable::GetCurrentPos() {
    return CurrPos;
}
