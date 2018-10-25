#ifndef RArrowKey_h
#define RArrowKey_h

#include "TKey.h"

namespace ROOT {

/*
 * a record class
 *   - key
 *   - binary buffer
 */
class RLinkRecord : public TKey {
public:
    RLinkRecord();
    RLinkRecord(std::string const& name, uint64_t size, TDirectory *);

    ClassDef(RLinkRecord, 1);

protected:
};

}

#endif // RArrowKey_h
