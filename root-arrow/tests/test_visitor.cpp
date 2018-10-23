#include <iostream>
#include <string>
#include <vector>

#include "particle.hpp"

// arrow stuff
#include <arrow/api.h>

// root
#include "RArrowInterface.hpp"
#include "TFile.h"

using particles = std::vector<hep::particle<float>> ;
std::vector<particles> generate(int num_entries, int max_num_particles) {
    std::vector<particles> batch;
    for (int i=0; i<num_entries; ++i) {
        particles ps;
        int num_particles = std::rand() % max_num_particles;
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
    arrow::PrettyPrint(*schema, {2}, &(std::cout));
    std::cout << std::endl;

    // vector of particles ListType
    std::shared_ptr<arrow::ListBuilder> vector_particles_builder{
        new arrow::ListBuilder{pool, particle_builder}
    };
    auto vector_particles_type = std::make_shared<arrow::ListType>(particle_type);

    // some debugging
    auto schema_final = std::make_shared<arrow::Schema>(vector_particles_type->children());
    arrow::PrettyPrint(*schema_final, {2}, &(std::cout));
    std::cout << std::endl;

    // iterate through all the rows and convert row-based to apache arrow data model
    for (auto const& entry : batch) {
        // for each particle of particles
        vector_particles_builder->Append();
        for (auto const& particle : entry) {
            // for each particle
            particle_builder->Append();

            //
            // particle fields
            //
            auto *position_builder = 
                static_cast<arrow::StructBuilder*>(particle_builder->field_builder(0));
            auto *momentum_builder = 
                static_cast<arrow::StructBuilder*>(particle_builder->field_builder(1));
            auto *charge_builder = 
                static_cast<arrow::Int32Builder*>(particle_builder->field_builder(2));
            auto *properties_builder = 
                static_cast<arrow::ListBuilder*>(particle_builder->field_builder(3));

            // position field
            position_builder->Append();
            auto const& [x, y, z] = particle.position;
            static_cast<arrow::FloatBuilder*>(position_builder->field_builder(0))
                ->Append(x);
            static_cast<arrow::FloatBuilder*>(position_builder->field_builder(1))
                ->Append(y);
            static_cast<arrow::FloatBuilder*>(position_builder->field_builder(2))
                ->Append(z);

            // momentum field
            momentum_builder->Append();
            auto const& [x1, y1, z1, t1] = particle.momentum;
            static_cast<arrow::FloatBuilder*>(momentum_builder->field_builder(0))
                ->Append(x1);
            static_cast<arrow::FloatBuilder*>(momentum_builder->field_builder(1))
                ->Append(y1);
            static_cast<arrow::FloatBuilder*>(momentum_builder->field_builder(2))
                ->Append(z1);
            static_cast<arrow::FloatBuilder*>(momentum_builder->field_builder(3))
                ->Append(t1);

            // charge field
            charge_builder->Append(particle.charge);

            // some_propoerties field
            properties_builder->Append();
            auto *properties_values_builder = 
                static_cast<arrow::Int32Builder*>(properties_builder->value_builder());
            properties_values_builder->AppendValues(
                particle.some_properties.data(), particle.some_properties.size(), 
                nullptr);
        }
    }

    // done building an arrow array
    vector_particles_builder->Finish(&result);

    return result;
}

std::vector<particles> to_row_based(std::shared_ptr<arrow::Array> const& array) {
    std::vector<particles> result;

    // get at a single entry level
    auto const* vector_particles_array = static_cast<arrow::ListArray*>(array.get());
    auto const* particles_values_array = static_cast<arrow::StructArray*>(vector_particles_array->values().get());
    auto particles_offsets_buffer = vector_particles_array->value_offsets();
    auto const *raw_particles_offsets = reinterpret_cast<uint32_t const*>(particles_offsets_buffer->data());

    // particle struct fields' arrays
    auto const *position_array = static_cast<arrow::StructArray*>(particles_values_array->field(0).get());
    auto const *momentum_array = static_cast<arrow::StructArray*>(particles_values_array->field(1).get());
    auto const *charge = static_cast<arrow::Int32Array*>(particles_values_array->field(2).get());
    auto const *some_properties = static_cast<arrow::ListArray*>(particles_values_array->field(3).get());

    // position fields' arrays
    auto const *position_x_array = static_cast<arrow::FloatArray*>(position_array->field(0).get());
    auto const *position_y_array = static_cast<arrow::FloatArray*>(position_array->field(1).get());
    auto const *position_z_array = static_cast<arrow::FloatArray*>(position_array->field(2).get());

    // momentum fields' arrays
    auto const *momentum_x_array = static_cast<arrow::FloatArray*>(momentum_array->field(0).get());
    auto const *momentum_y_array = static_cast<arrow::FloatArray*>(momentum_array->field(1).get());
    auto const *momentum_z_array = static_cast<arrow::FloatArray*>(momentum_array->field(2).get());
    auto const *momentum_t_array = static_cast<arrow::FloatArray*>(momentum_array->field(3).get());

    auto const* raw_properties_offsets = some_properties->raw_value_offsets();
    auto const *properties_values_array = static_cast<arrow::Int32Array*>(some_properties->values().get());
    
    // debugging
    std::cout << "arrow array size = " << array->length() << std::endl;
    std::cout << "arrow ofsets buffer size = " << particles_offsets_buffer->size() << std::endl;
    std::cout << "arrow offsets buffer capacity = " << particles_offsets_buffer->capacity() << std::endl;

    // for each event (a la entry or row)
    for (int entry=0; entry < array->length(); ++entry) {
        particles v;
        std::cout << "raw[" << entry << "] = " << raw_particles_offsets[entry] << std::endl;
        std::cout << "Entry = " << entry << " number of particles per entry = " << 
            raw_particles_offsets[entry+1] - raw_particles_offsets[entry] << std::endl;

        // for each particle 
        for (int j=raw_particles_offsets[entry]; j<raw_particles_offsets[entry+1]; j++) {
            hep::particle<float> particle {
                // build position
                {
                    position_x_array->raw_values()[j], position_y_array->raw_values()[j],
                    position_y_array->raw_values()[j]
                },
                // build momentum
                {
                     momentum_x_array->raw_values()[j], momentum_y_array->raw_values()[j],
                     momentum_z_array->raw_values()[j], momentum_t_array->raw_values()[j]
                },
                // charge
                charge->raw_values()[j],
                //std::vector<int>{5, 6, 7}
                // list of some properties
                std::vector<int>{
                    &properties_values_array->raw_values()[raw_properties_offsets[j]], 
                    &properties_values_array->raw_values()[raw_properties_offsets[j+1]]
                }
            };

            v.push_back(particle);
        }

        result.push_back(v);
    }

    return result;
}

void print_row_based(std::vector<particles> const& vs) {
    for (auto const& v : vs) {
        for (auto const& p : v) {
            std::cout << p << std::endl;
        }
    }
}

void test_write(std::shared_ptr<arrow::Array> const& array) {
    // root stuff
    std::unique_ptr<TFile> f{new TFile("test.root", "recreate")};

    // root - arrow interface
    ROOT::RArrowInterface interface{&*f};
    std::cout << std::endl;
    interface.WriteArray(array);

    // write the meta/linking record
    f->WriteObject<ROOT::RArrowInterface>(&interface, "root_arrow_interface");
    f->Close();
}

void print_link(ROOT::RLink const& link, std::string const& indent, std::string const& indent_symbol) {
    std::cout << indent << link.atype_name << "\n";
    std::cout << indent << link.record_position << "\n";
    for (auto const& child : link.children)
        print_link(child, indent + indent_symbol, indent_symbol);
}

void test_read() {
    std::unique_ptr<TFile> f{new TFile{"test.root"}};

    //ROOT::RArrowInterface *ptr = nullptr
    auto ptr = static_cast<ROOT::RArrowInterface*>(f->Get("root_arrow_interface"));
    auto const& top_link = ptr->TopLink();
    print_link(top_link, "", "\t\t");

    f->Close();
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "wrong number of cli arguments" << std::endl;
        exit(1);
    }

    int num_entries = std::stoi(argv[1]);
    int max_num_particles = std::stoi(argv[2]);

    auto row_based_batch = generate(num_entries, max_num_particles);
    auto arrow_based_batch = to_arrow_array(row_based_batch);
    
    // debugging
    arrow::PrettyPrint(*arrow_based_batch, {2}, &(std::cout));
    
    auto row_based_batch_back = to_row_based(arrow_based_batch);

    // debug the row based 
    print_row_based(row_based_batch_back);

    test_write(arrow_based_batch);
    test_read();
}
