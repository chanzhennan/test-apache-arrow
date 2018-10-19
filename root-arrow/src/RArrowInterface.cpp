#include "RArrowInterface.hpp"

ClassImp(ROOT::RArrowInterface);

namespace ROOT {

RArrowInterface::RArrowInterface()
    : dir{nullptr}
{}

RArrowInterface::RArrowInterface(TDirectory *dir)
    : dir{dir}
{}

RArrowInterface::~RArrowInterface() {}

}
