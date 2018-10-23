#include "RArrowInterface.hpp"
#include "RVisitors.hpp"

ClassImp(ROOT::RArrowInterface);

namespace ROOT {

RArrowInterface::RArrowInterface()
    : dir{nullptr}
{}

RArrowInterface::RArrowInterface(TDirectory *dir)
    : dir{dir}
{}

RArrowInterface::~RArrowInterface() {}

void RArrowInterface::WriteArray(std::shared_ptr<arrow::Array> const& arr) {
    // top link is the current link
    current_link = &top_link;

    // traverse the array and record
    RLinkBuilderVisitor visitor{*this};
    arr->Accept(&visitor);
}

}
