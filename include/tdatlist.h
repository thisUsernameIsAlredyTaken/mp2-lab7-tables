#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include "defines.h"

#include "tdatlink.h"

class TDatList {
  public:
    TDatList();
    ~TDatList() { DelList(); }
    
    PTDatValue GetDatValue(TLinkPos mode = CURRENT); 
    virtual int IsEmpty() { return pFirst == pStop; } 
    int GetListLength() { return ListLen; }       
    
    int SetCurrentPos(int pos);          
    int GetCurrentPos();       

    virtual int Reset();             
    virtual int IsListEnded(); 
    int GoNext();                    
                
    
    virtual void InsFirst(PTDatValue pVal = nullptr); 
    virtual void InsLast(PTDatValue pVal = nullptr); 
    virtual void InsCurrent(PTDatValue pVal = nullptr); 
    
    virtual void DelFirst();    
    virtual void DelCurrent();    
    virtual void DelList();    

  protected:
    PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
    void DelLink (PTDatLink pLink);   

    PTDatLink pFirst;    
    PTDatLink pLast;     
    PTDatLink pCurrLink; 
    PTDatLink pPrevLink; 
    PTDatLink pStop;     
    int CurrPos;         
    int ListLen;
};

#endif  
