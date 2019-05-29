#include "tdatlink.h"

TDatLink::TDatLink(PTDatValue pval, PTRootLink pn)
  : TRootLink(pn), PValue(pval) {}

void TDatLink::SetDatValue(PTDatValue pval) {
    PValue = pval;
}

PTDatValue TDatLink::GetDatValue() {
    return PValue;
}

PTDatLink TDatLink::GetNextDatLink() {
    return (PTDatLink)PNext;
}

