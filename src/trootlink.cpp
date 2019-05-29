#include "trootlink.h"

TRootLink::TRootLink(PTRootLink pn)
  : PNext(pn) {}

PTRootLink TRootLink::GetNextLink() {
    return PNext;
}

void TRootLink::SetNextLink(PTRootLink pl) {
    PNext = pl;
}

void TRootLink::InsNextLink(PTRootLink pl) {
    PTRootLink p = PNext;
    PNext = pl;
    if (pl != nullptr) {
        pl->PNext = p;
    }
}
