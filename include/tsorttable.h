#ifndef __TSORTTABLE_H__
#define __TSORTTABLE_H__

#include "defines.h"

#include "tscantable.h"

class TSortTable : public TScanTable {
  public:
    TSortTable(int Size = TabMaxSize): TScanTable(Size){};
    TSortTable(TScanTable &tab, TSortMethod sm = QUICK_SORT); 
    TSortTable &operator=(TScanTable &tab); 
    TSortMethod GetSortMethod();    
    void SetSortMethod(TSortMethod sm);
    
    virtual PTDatValue FindRecord(TKey k); 
    virtual void InsRecord(TKey k, PTDatValue pVal); 
    virtual void DelRecord(TKey k);        
    void Print(std::ostream& out);

  protected:
    void SortData();   
    void InsertSort(PTTabRecord *pMem, int DataCount); 
    void MergeSort(PTTabRecord *pMem, int DataCount);  
    void MergeSorter(PTTabRecord *a, PTTabRecord *tmp, int l, int r);
    void MergeData(PTTabRecord *a, PTTabRecord *tmp, int l, int c, int r);
    void QuickSort(PTTabRecord *pMem, int DataCount); 
    void QuickSplit(PTTabRecord *pData, int l, int r);

    TSortMethod SortMethod; 
};

#endif 
