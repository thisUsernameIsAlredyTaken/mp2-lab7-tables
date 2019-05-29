#ifndef __TARRAYTABLE_H__
#define __TARRAYTABLE_H__

#include "defines.h"

#include "ttable.h"

class TArrayTable : public TTable {
  public:
    TArrayTable(int Size = TabMaxSize);
    ~TArrayTable() {}

    virtual int IsFull();
    int GetTabSize();

    virtual TKey GetKey();
    virtual PTDatValue GetValuePtr();
    virtual TKey GetKey(TDataPos mode);
    virtual PTDatValue GetValuePtr(TDataPos mode);

    virtual PTDatValue FindRecord(TKey k) = 0;
    virtual void InsRecord(TKey k, PTDatValue pVal) = 0;
    virtual void DelRecord(TKey k) = 0;

    virtual int Reset();
    virtual int IsTabEnded();
    virtual int GoNext();

    virtual int SetCurrentPos (int pos);
    int GetCurrentPos();

  protected:
    PTTabRecord *pRecs;
    int TabSize;
    int CurrPos;
    friend class TSortTable;
};

#endif
