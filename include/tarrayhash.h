#ifndef __TARRAYHASH_H__
#define __TARRAYHASH_H__

#include "defines.h"

#include "thashtable.h"

class TArrayHash : public THashTable {
  public:
    TArrayHash(int Size = TabMaxSize, int Step = TabHashStep);
    ~TArrayHash();

    virtual int IsFull();

    virtual TKey GetKey();
    virtual PTDatValue GetValuePtr();

    virtual PTDatValue FindRecord(TKey k);
    virtual void InsRecord(TKey k, PTDatValue pVal);
    virtual void DelRecord(TKey k);

    virtual int Reset();
    virtual int IsTabEnded();
    virtual int GoNext() ;

  protected:
    PTTabRecord *pRecs;
    int TabSize;
    int HashStep;
    int FreePos;
    int CurrPos;
    PTTabRecord pMark;
    int GetNextPos(int pos) { return (pos + HashStep) % TabSize; };
};

#endif
