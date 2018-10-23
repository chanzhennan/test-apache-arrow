#ifndef RArrowInterface_h
#define RArrowInterface_h

#include "TNamed.h"
class TDirectory;

#include "arrow/array.h"

namespace ROOT {

class RLinkBuilderVisitor;

struct RLink {
    std::string atype_name;
    uint64_t record_position;
    std::vector<RLink> children;

    ClassDef(RLink, 1);
};

class RArrowInterface : public TNamed {
public:
    RArrowInterface();
    RArrowInterface(TDirectory *dir);
    virtual ~RArrowInterface();

    // main entry points for reading/writing arrow arrays
    void WriteArray(std::shared_ptr<arrow::Array> const&);

    // 
    inline RLink const& TopLink() { return top_link; }

    // visitor has access
    friend RLinkBuilderVisitor;

private:
    RLink top_link;
    RLink *current_link; //! ptr to the current link
    TDirectory *dir; //! reference to the directory

public:
    ClassDef(RArrowInterface, 1);
};

}

ClassImp(ROOT::RLink);

#endif // RArrowInterface_h
