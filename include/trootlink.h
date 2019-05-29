#ifndef __TROOTLINK_H__
#define __TROOTLINK_H__

#include "defines.h"

#include "tdatvalue.h"

class TRootLink {
  public:
    TRootLink(PTRootLink pn=nullptr);

    PTRootLink GetNextLink();
    void SetNextLink(PTRootLink pl);
    void InsNextLink(PTRootLink pl);

    virtual void SetDatValue(PTDatValue) = 0;
    virtual PTDatValue GetDatValue() = 0;

  protected:
    PTRootLink PNext;

    friend class TDatList;
};

#endif
