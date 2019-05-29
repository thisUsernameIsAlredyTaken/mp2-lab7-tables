#ifndef __TDATLINK_H__
#define __TDATLINK_H__

#include "defines.h"

#include "trootlink.h"

class TDatLink : public TRootLink {
  public:
    TDatLink(PTDatValue pval=nullptr,
            PTRootLink pnext=nullptr);
    
    void SetDatValue(PTDatValue pval) override;
    PTDatValue GetDatValue() override;

    PTDatLink GetNextDatLink();

  protected:
    PTDatValue PValue;

    friend class TDatList;
};

#endif
