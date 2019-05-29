#include "tarraytable.h"

TArrayTable::TArrayTable(int Size) {
    pRecs = new PTTabRecord[Size];
    for (int i = 0; i < Size; ++i)
        pRecs[i] = nullptr;
    TabSize = Size;
    DataCount = CurrPos = 0;
}

int TArrayTable::IsFull() {
    return DataCount >= TabSize;
}

int TArrayTable::GetTabSize() {
    return TabSize;
}

TKey TArrayTable::GetKey() {
    return GetKey(CURRENT_POS);
}

TKey TArrayTable::GetKey(TDataPos mode) {
    int pos = -1;
    if (!IsEmpty()) {
        switch(mode) {
        case FIRST_POS:
            pos = 0;
            break;
        case LAST_POS:
            pos = DataCount - 1;
            break;
        default:
            pos = CurrPos;
            break;
        }
    }
    if (pos == -1)
        return "";
    return pRecs[pos]->Key;
}

PTDatValue TArrayTable::GetValuePtr() {
    return GetValuePtr(CURRENT_POS);
}

PTDatValue TArrayTable::GetValuePtr(TDataPos mode) {
    int pos = -1;
    if (!IsEmpty()) {
        switch(mode) {
        case FIRST_POS:
            pos = 0;
            break;
        case LAST_POS:
            pos = DataCount - 1;
            break;
        default:
            pos = CurrPos;
            break;
        }
    }
    if (pos == -1)
        return nullptr;
    return pRecs[pos]->pValue;
}

int TArrayTable::Reset() {
    CurrPos = 0;
    return IsTabEnded();
}

int TArrayTable::IsTabEnded() {
    return CurrPos >= DataCount;
}

int TArrayTable::GoNext() {
    if (!IsTabEnded())
        ++CurrPos;
    return IsTabEnded();
}

int TArrayTable::SetCurrentPos(int pos) {
    CurrPos = (pos > -1 && pos < DataCount) ? pos : 0;
    return IsTabEnded();
}

int TArrayTable::GetCurrentPos() {
    return CurrPos;
}
