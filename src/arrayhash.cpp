#include "arrayhash.h"

TArrayHash::TArrayHash(int size, int step) {}

TArrayHash::~TArrayHash() {}

bool TArrayHash::IsFull() const {}

TKey TArrayHash::GetKey() const {}

PTDatValue TArrayHash::GetValuePtr() const {}

PTDatValue TArrayHash::FindRecord(TKey k) {}

void TArrayHash::InsRecord(TKey k, PTDatValue pVal) {}

void TArrayHash::DelRecord(TKey k) {}

bool TArrayHash::Reset() {}

bool TArrayHash::IsTabEnded() const {}

bool TArrayHash::GoNext() {}

int TArrayHash::GetNextPos(int pos) {
    return (pos + HashStep) % TabSize;
}
