#ifndef __THASHTABLE_H__
#define __THASHTABLE_H__

#include "defines.h"

#include "ttable.h"

class THashTable : public TTable {
  public:
    THashTable();

  protected:
    virtual unsigned long HashFunc(TKey k);
};


#endif
