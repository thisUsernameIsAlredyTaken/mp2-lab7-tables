#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include "defines.h"

#include "tarraytable.h"

class TScanTable : public TArrayTable {
  public:
    TScanTable(int size=TabMaxSize);

    PTDatValue FindRecord(const TKey &k) override;
    virtual void InsRecord(const TKey &k,
            PTDatValue pval) override;
    void DelRecord(const TKey &k) override;
};


#endif
