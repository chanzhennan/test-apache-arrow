#ifndef RArrowInterface_h
#define RArrowInterface_h

#include "TNamed.h"

class TDirectory;

namespace ROOT {

class RArrowInterface : public TNamed {
public:
    RArrowInterface();
    RArrowInterface(TDirectory *dir);
    virtual ~RArrowInterface();

private:
    int x, y, z;
    TDirectory *dir; //! reference to the directory
//    TFile const& file; ///<! file to write to

public:
    ClassDef(RArrowInterface, 1);
};

}

#endif // RArrowInterface_h
