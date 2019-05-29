#ifndef __TARRAYTABLE_H__
#define __TARRAYTABLE_H__

#include "defines.h"

#include "ttable.h"

class TArrayTable : public TTable {
  public:
    TArrayTable(int size=TabMaxSize);
    ~TArrayTable();

    bool IsFull() override;
    int GetTabSize();

    TKey GetKey() override;
    PTDatValue GetValuePtr() override;
    virtual TKey GetKey(TDataPos mode);
    virtual PTDatValue GetDatValuePtr(TDataPos mode);

    virtual PTDatValue FindRecord(const TKey &k) = 0;
    virtual void InsRecord(const TKey &k, PTDatValue pval) = 0;
    virtual void DelRecord(const TKey &k) = 0;

    void Reset() override;
    bool IsTabEnded() override;
    bool GoNext() override;

    virtual void SetCurrentPos(int pos);
    int GetCurrentPos();

  protected:
    PTTabRecord *PRecs;
    int TabSize;
    int CurrPos;

    friend class TSortTable;
};

#endif
