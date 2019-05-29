#include "thashtable.h"

unsigned long THashTable::HashFunc(TKey key) {
    unsigned long hashval = 0;
    for (int i = 0; i < key.size(); ++i)
        hashval = (hashval << 3) + key[i];
    return hashval;
}
