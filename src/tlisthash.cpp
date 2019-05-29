#include "tlisthash.h"

#include "ttabrecord.h"
#include "tword.h"

TListHash::TListHash(int Size) : THashTable() {
    pList = new PTDatList[Size];
    TabSize = Size;
    CurrList = 0;
    for (int i = 0; i < TabSize; ++i)
        pList[i] = new TDatList;
}

TListHash::~TListHash() {
    for (int i = 0; i < TabSize; ++i)
        delete pList[i];
    delete[] pList;
}

PTDatValue TListHash::FindRecord(TKey k) {
    PTDatValue pValue = nullptr;
    CurrList = HashFunc(k) % TabSize;
    PTDatList pL = pList[CurrList];
    for (pL->Reset(); !pL->IsListEnded(); pL->GoNext()) {
        if (PTTabRecord(pL->GetDatValue())->Key == k) {
            pValue = PTTabRecord(pL->GetDatValue())->pValue;
            break;
        }
    }
    Efficiency += pL->GetCurrentPos() + 1;
    return pValue;
}

void TListHash::InsRecord(TKey k, PTDatValue pVal) {
    CurrList = HashFunc(k) % TabSize;
    pList[CurrList]->InsLast(new TTabRecord(k, pVal));
    ++DataCount;
    ++Efficiency;
}

void TListHash::DelRecord(TKey k) {
    int delpos = HashFunc(k) % TabSize;

    PTDatList pL = pList[delpos];

    for (pL->Reset(); !pL->IsListEnded(); pL->GoNext()) {
        ++Efficiency;
        if (PTTabRecord(pL->GetDatValue())->Key == k) {
            pL->DelCurrent();
            --DataCount;
            break;
        }
    }

    Reset();
}

int TListHash::Reset() {
    CurrList = 0;
    pList[CurrList]->Reset();

    return IsTabEnded();
}

int TListHash::GoNext() {
    if (!pList[CurrList]->IsListEnded()) {
        pList[CurrList]->GoNext();
    }

    if (pList[CurrList]->IsListEnded()) {
        ++CurrList;

        while (CurrList < TabSize && pList[CurrList]->IsEmpty()) {
            ++CurrList;
        }

        if (CurrList < TabSize) {
            pList[CurrList]->Reset();
        }
    }

    return IsTabEnded();
}

int TListHash::IsTabEnded() {
    return CurrList >= TabSize;
}

int TListHash::IsFull() {
    return 0;
}

TKey TListHash::GetKey() {
    if (CurrList < 0 || CurrList >= TabSize) {
        return "";
    }

    PTTabRecord pRec = PTTabRecord(pList[CurrList]->GetDatValue());

    return pRec ? pRec->Key : "";
}

PTDatValue TListHash::GetValuePtr() {
    if (CurrList < 0 || CurrList >= TabSize) {
        return nullptr;
    }

    PTTabRecord pRec = PTTabRecord(pList[CurrList]->GetDatValue());

    return pRec ? pRec->pValue : nullptr;
}
