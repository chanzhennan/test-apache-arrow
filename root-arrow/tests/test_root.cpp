#include <iostream>

#include "TFile.h"
#include "TKey.h"

void test1() {
    std::unique_ptr<TFile> f{new TFile{"test_root.root", "recreate"}};

    TKey *key = new TKey{&*f};
    key->Write();
    f->Write();
    f->Close();
}

int main() {
    test1();

    return 0;
}
