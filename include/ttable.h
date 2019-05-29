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

    virtual PTDatValue FindRecord(TKey k) = 0;
    virtual void InsRecord(TKey k,
            PTDatValue pval) = 0;
    virtual void DelRecord(TKey k) = 0;

    virtual void Reset() = 0;
    virtual bool IsTabEnded() = 0;
    virtual bool GoNext() = 0;

  protected:
    int DataCount;
    int Efficiency;
};


#endif
