// std headers
#include <iostream>

// arrow headers
#include <arrow/api.h>

using namespace arrow;

int main() {

    Int64Builder builder;
    builder.Append(1);
    builder.Append(2);
    builder.Append(3);
    builder.AppendNull();
    builder.Append(5);
    builder.Append(6);
    builder.Append(7);
    builder.Append(8);

    std::shared_ptr<Array> array;
    builder.Finish(&array);

    std::shared_ptr<Int64Array> int64_array = std::static_pointer_cast<Int64Array>(array);
    uint8_t const* null_bitmap = int64_array->null_bitmap_data();

    int64_t const* data = int64_array->raw_values();

    std::cout << "length = " << int64_array->length() << std::endl;
}
