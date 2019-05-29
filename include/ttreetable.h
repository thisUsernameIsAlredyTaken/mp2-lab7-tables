#ifndef __TTREETABLE_H__
#define __TTREETABLE_H__

#include "defines.h"

#include "ttable.h"
#include "ttreenode.h"

#include <stack>

class TTreeTable: public TTable {
  public:
    TTreeTable(): TTable() {
        CurrPos = 0;
        pRoot = pCurrent = nullptr;
        ppRef = nullptr;
    }
    ~TTreeTable() {DeleteTreeTab(pRoot);} 
    
    virtual int IsFull(); 
    
    virtual PTDatValue FindRecord(TKey k); 
    virtual void InsRecord(TKey k, PTDatValue pVal); 
    virtual void DelRecord(TKey k);       
    void Print(PTTreeNode pNode, int depth = 0);
    void Print() {Print(pRoot);}
    
    virtual TKey GetKey();
    virtual PTDatValue GetValuePtr();
    virtual int Reset();  
    virtual int IsTabEnded(); 
    virtual int GoNext();
    
  protected:
    void DeleteTreeTab (PTTreeNode pNode); 
    
    PTTreeNode pRoot; 
    PTTreeNode *ppRef;
    PTTreeNode pCurrent;
    int CurrPos;        
    std::stack <PTTreeNode> St;
};

#endif 
