#ifndef __TWORD_H__
#define __TWORD_H__

#include "defines.h"

#include "tdatvalue.h"

#include <string>

class TWord : public TDatValue {
  public:
    TWord(const std::string &w);

    PTDatValue GetCopy() override;

    std::string GetWord();
    void SetWord(const std::string &w);

    bool operator==(const TWord &w);

  protected:
    std::string word;
};

#endif
