#include <iostream>

// root headers
#include "TFile.h"

// root-arrow 
#include "RArrowInterface.hpp"

int main(int argc, char **argv) {
    TFile *f = new TFile("test.root", "recreate");

    // create an interface
    std::unique_ptr<ROOT::RArrowInterface> ptr {new ROOT::RArrowInterface{1,2,3}};

    // write
    f->WriteObject<ROOT::RArrowInterface>(ptr.get(), "test_interface");
    f->Close();

    std::cout << "hello world" << std::endl;
}
