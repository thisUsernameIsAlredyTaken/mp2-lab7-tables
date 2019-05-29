#ifndef __TLISTHASH_H__
#define __TLISTHASH_H__

#include "defines.h"

#include "thashtable.h"
#include "tdatlist.h"

class TListHash : public THashTable {
  public:
    TListHash(int Size = TabMaxSize); 
    ~TListHash();
    
    virtual int IsFull(); 
    
    virtual TKey GetKey();
    virtual PTDatValue GetValuePtr();
    
    virtual PTDatValue FindRecord(TKey k); 
    virtual void InsRecord(TKey k, PTDatValue pVal); 
    virtual void DelRecord(TKey k);        
    
    virtual int Reset();   
    virtual int IsTabEnded(); 
    virtual int GoNext(); 
    
  protected:
    PTDatList *pList; 
    int TabSize;      
    int CurrList;     
};

#endif 
