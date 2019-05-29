#include "tdatlist.h"

TDatList::~TDatList() {
    DelList();
}

bool TDatList::IsEmpty() {
    return PFirst == PStop;
}

int TDatList::GetListLength() {
    return ListLen;
}

