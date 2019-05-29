#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include "defines.h"

#include "tarraytable.h"

class TScanTable : public TArrayTable {
  public:
    TScanTable(int Size = TabMaxSize): TArrayTable(Size) {};
    
    virtual PTDatValue FindRecord(TKey k); 
    virtual void InsRecord(TKey k, PTDatValue pVal); 
    virtual void DelRecord(TKey k); 
};

#endif 
