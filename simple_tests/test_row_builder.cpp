// std headers
#include <iostream>

// arrow headers
#include <arrow/api.h>

using namespace arrow;

struct data_row_t {
    data_row_t(int64_t id_, double cost_, std::vector<double> v)
        : id(id_), cost(cost_), cost_components(std::move(v))
    {}
    data_row_t(data_row_t const& other) :
        id(other.id), cost(other.cost), cost_components(other.cost_components)
    {}
    data_row_t(data_row_t&& other) :
        id(other.id), cost(other.cost), cost_components(std::move(other.cost_components))
    {}
    int64_t id;
    double cost;
    std::vector<double> cost_components;
};

int main() {

    std::vector<data_row_t> rows;

    std::cout << "111" << std::endl;

    for (int64_t i=0; i<100; i++) {
        std::vector<double> tmp {1.5, 2.5, 3.5};
        rows.emplace_back(
            i, double(i), tmp
        );
    }

    std::cout << "222" << std::endl;

    using arrow::DoubleBuilder;
    using arrow::Int64Builder;
    using arrow::ListBuilder;

    arrow::MemoryPool *pool = arrow::default_memory_pool();
    Int64Builder id_builder(pool);
    DoubleBuilder cost_builder(pool);
    std::unique_ptr<DoubleBuilder> components_values_builder(new DoubleBuilder(pool));
    ListBuilder components_builder(pool, std::move(components_values_builder));
    
    std::cout << "333" << std::endl;

    for (auto const& row : rows) {
        id_builder.Append(row.id);
        cost_builder.Append(row.cost);
        components_builder.Append();
        DoubleBuilder* bld = static_cast<DoubleBuilder*>(components_builder.value_builder());
        bld->AppendValues(
            row.cost_components.data(), row.cost_components.size(), nullptr);
    }

    std::cout << "444" << std::endl;

    std::shared_ptr<arrow::Array> id_array;
    id_builder.Finish(&id_array);
    std::shared_ptr<arrow::Array> cost_array;
    cost_builder.Finish(&cost_array);
    std::shared_ptr<arrow::Array> cost_components_array;
    components_builder.Finish(&cost_components_array);

    std::vector<std::shared_ptr<arrow::Field>> schema_vector = {
        arrow::field("id", arrow::int64()),
        arrow::field("cost", arrow::float64()),
        arrow::field("cost_components", arrow::list(arrow::float64()))
    };
    auto schema = std::make_shared<arrow::Schema>(schema_vector);

    std::shared_ptr<arrow::Table> table = arrow::Table::Make(schema, {id_array, cost_array, cost_components_array});

    arrow::PrettyPrint(*schema, {5}, &(std::cout));
    std::cout << std::endl;

    arrow::PrettyPrint(*id_array, {2}, &(std::cout));
    std::cout << std::endl;

    arrow::PrettyPrint(*cost_array, {2}, &(std::cout));
    std::cout << std::endl;

    arrow::PrettyPrint(*cost_components_array, {2}, &std::cout);
    std::cout << std::endl;
}
