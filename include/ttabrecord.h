#ifndef __TTABRECORD_H__
#define __TTABRECORD_H__

#include "defines.h"

#include "tdatvalue.h"

#include <string>

class TTabRecord : public TDatValue {
  public:  
    TTabRecord (TKey k = "", PTDatValue pVal = nullptr) : Key(k), pValue(pVal) {}; 
    void SetKey(TKey k); 
    TKey GetKey();  
    void SetValuePtr(PTDatValue p);
    PTDatValue GetValuePtr(); 
    virtual PTDatValue GetCopy(); 
    TTabRecord &operator=(TTabRecord &tr);
    virtual bool operator==(const TTabRecord &tr); 
    virtual bool operator<(const TTabRecord &tr);  
    virtual bool operator>(const TTabRecord &tr);  

  protected:    
    TKey Key;   
    PTDatValue pValue;   
    
    friend class TArrayTable;
    friend class TScanTable;
    friend class TSortTable;
    friend class TTreeNode;
    friend class TTreeTable;
    friend class TArrayHash;
    friend class TListHash;
};

#endif  
