#ifndef __TSORTTABLE_H__
#define __TSORTTABLE_H__

#include "defines.h"

#include "tscantable.h"

#include <iostream>

class TSortTable : public TScanTable {
  public:
    TSortTable(int size=TabMaxSize);
    TSortTable(const TScanTable &tsc,
            TSortMethod sm=QUICK_SORT);

    TSortTable& operator=(const TScanTable &tsc);

    TSortMethod GetSortMethod();
    void SetSortMethod(TSortMethod sm);

    PTDatValue FindRecord(const TKey &k) override;
    void InsRecord(const TKey &k,
            PTDatValue pval) override;
    void DelRecord(const TKey &k) override;

    void Print(std::ostream &os);

  protected:
    void SortData();

    void InsertSort(PTTabRecord *pmem,
            int datacount);

    void MergeSort(PTTabRecord *pmem,
            int datacount);
    void MergeSorter(PTTabRecord *a,
            PTTabRecord *tmp, int l, int r);
    void MegreData(PTTabRecord *a,
            PTTabRecord *tmp, int l, int c, int r);

    void QuickSort(PTTabRecord *pmem,
            int datacount);
    void QuickSplit(PTTabRecord *pdata,
            int l, int r);

    TSortMethod SortMethod;
};



#endif
