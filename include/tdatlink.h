#ifndef __TDATLINK_H__
#define __TDATLINK_H__

#include "defines.h"

#include "trootlink.h"

class TDatLink : public TRootLink {
  public:
    TDatLink (PTDatValue pVal = nullptr, PTRootLink pN = nullptr) :
        TRootLink(pN) {
        pValue = pVal;
    }
    void SetDatValue(PTDatValue pVal) { pValue = pVal; }
    PTDatValue GetDatValue() { return  pValue; }
    PTDatLink GetNextDatLink() { return  (PTDatLink)pNext; }

  protected:
    PTDatValue pValue;  
    
    friend class TDatList;
};

#endif  
