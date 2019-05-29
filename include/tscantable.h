#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include "defines.h"

#include "tarraytable.h"

class TScanTable : public TArrayTable {
  public:
    TScanTable(int size=TabMaxSize);

    PTDatValue FindRecord(TKey k) override;
    virtual void InsRecord(TKey k,
            PTDatValue pval) override;
    void DelRecord(TKey k) override;
};


#endif
