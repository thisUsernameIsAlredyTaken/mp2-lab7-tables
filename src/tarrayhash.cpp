#include "tarrayhash.h"

#include "ttabrecord.h"

TArrayHash::TArrayHash(int size, int step)
      : PRecs(new PTTabRecord[size]),
        TabSize(size), HashStep(step),
        PMark(new TTabRecord("", nullptr)) {
    for (int i = 0; i < TabSize; ++i) {
        PRecs[i] = PMark;
    }
}

TArrayHash::~TArrayHash() {
    for (int i = 0; i < TabSize; ++i) {
        if (PRecs[i] && PRecs[i] != pMark) {
            delete PRecs[i];
        }
    }
    delete[] PRecs;
    delete PMark;
}

PTDatValue TArrayHash::FindRecord(TKey k) {
    PTDatValue pval = nullptr;
    FreePos = -1;
    CurrPos = HashFunc(k) & TabSize;
    for (int i = 0; i < TabSize; ++i) {
        ++Efficiency;
        if (!PRecs[CurrPos]) {
            break;
        }
        if (PRecs[CurrPos] == PMark) {
            if (FreePos == -1) {
                FreePos = CurrPos;
            }
        } else if (PRecs[CurrPos]->Key == k) {
            pval = PRecs[CurrPos]->pval;
            break;
        }
        CurrPos = GetNextPos(CurrPos);
    }

    return pval;
}

void TArrayHash::InsRecord(TKey k, PTDatValue pval) {
    if (DataCount >= TabSize) {
        throw "no memoty";
    }

    int currpos = HashFunc(k) % TabSize;

    while (PRecs[CurrPos] != PMark) {
        ++Efficiency;
        currpos = GetNextPos(currpos);
    }
    PRecs[currpos] = new TTabRecord(k, pval);

    ++DataCount;
}

void TArrayHash::DelRecord(TKey k) {
    PTDatValue tmp = FindRecord(k);
    if (tmp == nullptr) {
        return;
    }

    PRecs[CurrPos] = PMark;
    --DataCount;
}

void TArrayHash::Reset() {
    CurrPos = 0;
}

bool TArrayHash::IsFull() {
    return DataCount == TabSize;
}

bool TArrayHash::IsTabEnded() {
    return CurrPos >= TabSize;
}

bool TArrayHash::GoNext() {
    if (!IsTabEnded()) {
        while (++CurrPos < TabSize) {
            if (PRecs[CurrPos] != nullptr &&
                    PRecs[CurrPos] != PMark) {
                break;
            }
        }
    }
    return IsTabEnded();
}

int TArrayHash::GetNextPos(int pos) {
    return (pos + HashStep) % TabSize;
}

TKey TArrayHash::GetKey() {
    if (CurrPos < 0 || CurrPos >= TabSize) {
        return "";
    } else {
        return PRecs[CurrPos]->PValue;
    }
}

PTDatValue TArrayHash::GetValuePtr() {
    if (CurrPos < 0 || CurrPos >= TabSize) {
        return nullptr;
    } else {
        return PRecs[CurrPos]->PValue;
    }
}
