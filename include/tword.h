#ifndef __TWORD_H__
#define __TWORD_H__

#include "defines.h"

#include "tdatvalue.h"

#include <string>

class TWord : public TDatValue {
  public:
    TWord(std::string w) : word(w) {}
    virtual PTDatValue GetCopy(); 
    std::string GetWord() {return word;}
    void SetWord(const std::string &w) {word = w;}
    bool operator==(const TWord &w) {return w.word == word;}

  protected:
    std::string word;
};

#endif  
