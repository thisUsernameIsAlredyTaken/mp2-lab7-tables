#ifndef __TTABLE_H__
#define __TTABLE_H__

#include "defines.h"

class TTable {
  public:
    TTable();
    virtual ~TTable();

    int GetDataCount();
    int GetEfficiency();

    void ResetsEfficiency();

    bool IsEmpty();
    virtual bool IsFull() = 0;

    virtual TKey GetKey() = 0;
    virtual PTDatValue GetValuePtr() = 0;

    virtual PTDatValue FindRecord(const TKey &k) = 0;
    virtual void InsRecord(const TKey &k,
            PTDatValue pval) = 0;
    virtual void DelRecord(const TKey &k) = 0;

    virtual void Reset() = 0;
    virtual bool IsTabEnded() = 0;
    virtual bool GoNext() = 0;

  protected:
    int DataCount;
    int Efficiency;
};


#endif
