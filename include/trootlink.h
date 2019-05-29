#ifndef __TROOTLINK_H__
#define __TROOTLINK_H__

#include "defines.h"

#include "tdatvalue.h"

class TRootLink {
  public:
    TRootLink(PTRootLink pN = nullptr) { pNext = pN; }
    PTRootLink  GetNextLink() { return  pNext; }
    void SetNextLink(PTRootLink pLink) { pNext = pLink; }
    void InsNextLink(PTRootLink pLink) {
        PTRootLink p = pNext;
        pNext = pLink;
        if (pLink)
            pLink->pNext = p;
    }
    virtual void SetDatValue(PTDatValue pVal) = 0;
    virtual PTDatValue GetDatValue() = 0;

  protected:
    PTRootLink pNext;  

    friend class TDatList;
};

#endif  
