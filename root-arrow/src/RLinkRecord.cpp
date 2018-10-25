#include "RLinkRecord.hpp"

ClassImp(ROOT::RLink);

namespace ROOT {

RLinkRecord::RLinkRecord()
    : TKey{}
{}

RLinkRecord::RLinkRecord(std::string const& name, uint32_t size, TDirectory *dir)
    : TKey{dir}
{
    // analogous to TBasket
    SetTitle(name.c_str());
    SetName(name.c_str());

    Create(size, nullptr);
}

}
