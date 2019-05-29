#ifndef __TLISTHASH_H__
#define __TLISTHASH_H__

#include "defines.h"

#include "thashtable.h"

class TListHash : public THashTable {
  protected:
    PTDatList *PList;
    int TabSize;
    int CurrList;

  public:
    TListHash(int size=TabMaxSize);
    ~TListHash();

    bool IsFull() override;

    TKey GetKey() override;
    PTDatValue GetValuePtr() override;

    PTDatValue FindRecord(const TKey &k) override;
    void InsRecord(const TKey &k, PTDatValue pval) override;
    void DelRecord(const TKey &k);

    void Reset() override;
    bool IsTabEnded() override;
    bool GoNext() override;
};

#endif
