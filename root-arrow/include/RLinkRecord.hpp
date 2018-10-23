#ifndef RArrowKey_h
#define RArrowKey_h

#include "TKey.h"

namespace ROOT {

//////////////////////////////////////////////////////////////////////////
//
// RLinkRecord - a true record on disk
//   - key (through inheritance)
//   - buffer 
//
//////////////////////////////////////////////////////////////////////////

class RLinkRecord : public TKey {
public:
    RLinkRecord(std::string const& name, TDirectory *);

protected:
};

}

#endif // RArrowKey_h
