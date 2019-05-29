#ifndef __TTABLE_H__
#define __TTABLE_H__

#include "defines.h"

#include "ttabrecord.h"

class TTable {
  public:
    TTable(){ DataCount = 0; Efficiency = 0;} 
    virtual ~TTable() {}; 
    
    int GetDataCount() { return DataCount; }    
    int GetEfficiency() { return Efficiency; } 
    void ResetEfficiency() {Efficiency = 0;}
    int IsEmpty() { return DataCount == 0; }   
    virtual int IsFull() = 0;                 
    
    virtual TKey GetKey() = 0;
    virtual PTDatValue GetValuePtr() = 0;
    
    virtual PTDatValue FindRecord(TKey k) = 0; 
    virtual void InsRecord(TKey k, PTDatValue pVal) = 0; 
    virtual void DelRecord(TKey k) = 0;        
    
    virtual int Reset() = 0; 
    virtual int IsTabEnded() = 0; 
    virtual int GoNext() = 0; 
    
  protected:
    int DataCount;  
    int Efficiency; 
};

#endif 
