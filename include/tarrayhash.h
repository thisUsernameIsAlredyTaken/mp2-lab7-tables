#ifndef __TARRAYHASH_H__
#define __TARRAYHASH_H__

#include "defines.h"

#include "thashtable.h"

class TArrayHash : public THashTable {
  public:
    TArrayHash(int size=TabMaxSize,
            int step=TabHashStep);
    ~TArrayHash();

    bool IsFull() override;

    TKey GetKey() override;
    PTDatValue GetValuePtr() override;

    PTDatValue FindRecord(const TKey &k) override;
    void InsRecord(const TKey &k, PTDatValue pval) override;
    void DelRecord(const TKey &k) override;

    void Reset() override;
    bool IsTabEnded() override;
    bool GoNext() override;

  protected:
    int GetNextPos(int pos);

    PTTabRecord *PRecs;
    int TabSize;
    int HashStep;
    int FreePos;
    int CurrPos;
    PTTabRecord PMark;
};

#endif
