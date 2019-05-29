#ifndef __TDATVALUE_H__
#define __TDATVALUE_H__

#include "defines.h"

class TDatValue {
  public:
    virtual PTDatValue GetCopy() = 0; 
};

#endif  
