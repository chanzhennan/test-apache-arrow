#include <iostream>

#include "TFile.h"
#include "RLinkRecord.hpp"

void test1() {
    std::unique_ptr<TFile> f{new TFile{"test_root.root", "recreate"}};

    ROOT::RLinkRecord *record = new ROOT::RLinkRecord{"hello_record", 10u, &*f};
    std::cout << "GetSeekKey = " << record->GetSeekKey() << std::endl; 

    auto buffer =  record->GetBuffer();
    *buffer = 3;
    record->WriteFile();
    f->Write();
    f->Close();
}

int main() {
    test1();

    return 0;
}
