#include <iostream>

// root headers
#include "TFile.h"

// root-arrow 
#include "RArrowInterface.hpp"

int main(int argc, char **argv) {
    std::unique_ptr<TFile> f{new TFile("test.root", "recreate")};

    // create an interface
    std::shared_ptr<arrow::Array> arr;
    ROOT::RArrowInterface interface{&*f};
    interface.WriteArray(arr);

    // write
    f->WriteObject<ROOT::RArrowInterface>(&interface, "test_interface");
    f->Close();

    std::cout << "hello world" << std::endl;
}
