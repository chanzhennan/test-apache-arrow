#include <iostream>
#include <string>
#include <vector>

#include "particle.hpp"

// arrow stuff
#include <arrow/api.h>

using particles = std::vector<hep::particle<float>> ;
std::vector<particles> generate(int num_entries, int num_particles) {
    std::vector<particles> batch;
    for (int i=0; i<num_entries; ++i) {
        particles ps;
        for (int j=0; j<num_particles; ++j) {
            ps.push_back(hep::particle<float>::get_random());
        }
        batch.push_back(ps);
    }

    return batch;
}

std::shared_ptr<arrow::Array> to_arrow_array(std::vector<particles> batch) {
    std::shared_ptr<Array> result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "wrong number of cli arguments" << std::endl;
        exit(1);
    }

    int num_entries = std::stoi(argv[1]);
    int num_particles = std::stoi(argv[2]);

    auto batch = generate(num_entries, num_particles);
}
