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
    std::shared_ptr<arrow::Array> result;

    // arrow array builders
    // builders are initialized bottom up

    // builders for particle struct fields
    auto *pool = arrow::default_memory_pool();
    using tuple3_builder = std::array<arrow::FloatBuilder, 3>;

    // momentum field
    std::vector<std::shared_ptr<arrow::ArrayBuilder>> momentum_values_builders {
        std::make_shared<arrow::FloatBuilder>(pool),
        std::make_shared<arrow::FloatBuilder>(pool),
        std::make_shared<arrow::FloatBuilder>(pool),
        std::make_shared<arrow::FloatBuilder>(pool)
    };
    std::shared_ptr<arrow::StructType> momentum_type {new arrow::StructType{
        std::vector<std::shared_ptr<arrow::Field>>{
            std::make_shared<arrow::Field>("x", std::make_shared<arrow::FloatType>(), false), 
            std::make_shared<arrow::Field>("y", std::make_shared<arrow::FloatType>(), false),
            std::make_shared<arrow::Field>("z", std::make_shared<arrow::FloatType>(), false), 
            std::make_shared<arrow::Field>("t", std::make_shared<arrow::FloatType>(), false)
        }
    }};
    std::shared_ptr<arrow::StructBuilder> momentum_builder { new arrow::StructBuilder{momentum_type, pool, 
        std::move(momentum_values_builders)}};
    
    // position field
    std::vector<std::shared_ptr<arrow::ArrayBuilder>> position_values_builders {
        std::make_shared<arrow::FloatBuilder>(pool),
        std::make_shared<arrow::FloatBuilder>(pool),
        std::make_shared<arrow::FloatBuilder>(pool)
    };
    std::shared_ptr<arrow::StructType> position_type {new arrow::StructType{
        std::vector<std::shared_ptr<arrow::Field>>{
            std::make_shared<arrow::Field>("x", std::make_shared<arrow::FloatType>(), false), 
            std::make_shared<arrow::Field>("y", std::make_shared<arrow::FloatType>(), false),
            std::make_shared<arrow::Field>("z", std::make_shared<arrow::FloatType>(), false), 
        }
    }};
    std::shared_ptr<arrow::StructBuilder> position_builder{ new arrow::StructBuilder{position_type, pool, 
        std::move(position_values_builders)}};
    
    // charge field
    std::shared_ptr<arrow::Int32Builder> charge_builder{ new arrow::Int32Builder{pool}};
    auto charge_type = std::make_shared<arrow::Int32Type>();

    // some properties field
    std::unique_ptr<arrow::Int32Builder> prop_values_builder{new arrow::Int32Builder{pool}};
    std::shared_ptr<arrow::ListBuilder> properties_builder{ 
        new arrow::ListBuilder{pool, std::move(prop_values_builder)}};
    auto properties_type = std::make_shared<arrow::ListType>(std::make_shared<arrow::Int32Type>());

    // builder for the particle struct itself
    std::vector<std::shared_ptr<arrow::ArrayBuilder>> particle_values_builders {
        position_builder, momentum_builder, 
        charge_builder, properties_builder
    };
    std::shared_ptr<arrow::StructType> particle_type { new arrow::StructType {
        std::vector<std::shared_ptr<arrow::Field>>{
            std::make_shared<arrow::Field>("position", position_type, false),
            std::make_shared<arrow::Field>("momentum", momentum_type, false),
            std::make_shared<arrow::Field>("charge", charge_type, false),
            std::make_shared<arrow::Field>("some_properties", properties_type, false)
        }
    }};
    std::shared_ptr<arrow::StructBuilder> particle_builder{
        new arrow::StructBuilder{particle_type, pool, std::move(particle_values_builders)}
    };

    // some debuggin
    auto schema = std::make_shared<arrow::Schema>(particle_type->children());
    std::cout << std::endl;
    arrow::PrettyPrint(*schema, {5}, &(std::cout));
    std::cout << std::endl;

    for (auto const& entry : batch) {
        continue;
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "wrong number of cli arguments" << std::endl;
        exit(1);
    }

    int num_entries = std::stoi(argv[1]);
    int num_particles = std::stoi(argv[2]);

    auto row_based_batch = generate(num_entries, num_particles);
    auto arrow_based_batch = to_arrow_array(row_based_batch);
}