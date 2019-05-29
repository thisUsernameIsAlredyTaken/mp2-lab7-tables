#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include "defines.h"

class TDatList {
  public:
    TDatList();
    ~TDatList();

    PTDatValue GetDatValue(TLinkPos mode=CURRENT);
    virtual bool IsEmpty();
    int GetListLength();

    void SetCurrentPos(int pos);
    int GetCurrentPos();
    virtual void Reset();
    virtual bool IsListEnded();
    bool GoNext();

    virtual void InsFirst(PTDatValue pval=nullptr);
    virtual void InsLast(PTDatValue pval=nullptr);
    virtual void InsCurrent(PTDatValue pval=nullptr);

    virtual void DelFirst();
    virtual void DelCurrent();
    virtual void DelList();

  protected:
    PTDatLink GetLink(PTDatValue pval=nullptr,
            PTDatLink pl=nullptr);
    void DelLink(PTDatLink pl);

    PTDatLink PFirst;
    PTDatLink PLast;
    PTDatLink PCurrLink;
    PTDatLink PPrevLink;
    PTDatLink PStop;
    int CurrPos;
    int ListLen;
};

#endif
