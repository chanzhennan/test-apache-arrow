#include <iostream>

#include "RVisitors.hpp"

namespace ROOT {

arrow::Status RLinkBuilderVisitor::Visit(const arrow::NullArray& array) {
    std::cout << "null array visit" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::BooleanArray& array) {
    std::cout << "bool array" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int8Array& array) {
    std::cout << "int8 array" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int16Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt8Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt16Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::HalfFloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::FloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::DoubleArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::StringArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::BinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::FixedSizeBinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Date32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Date64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Time32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Time64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::TimestampArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::IntervalArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Decimal128Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::ListArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK() &
        array.values()->Accept(this);
}
arrow::Status RArrayVisitor::Visit(const arrow::StructArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    auto ok = arrow::Status::OK();
    for (int ifield=0; ifield<array.num_fields(); ++ifield)
        ok &= array.field(ifield)->Accept(this);
    return arrow::Status::OK() & ok;

}
arrow::Status RArrayVisitor::Visit(const arrow::UnionArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::DictionaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}

arrow::Status RArrayVisitor::Visit(const arrow::NullArray& array) {
    std::cout << "null array visit" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::BooleanArray& array) {
    std::cout << "bool array" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int8Array& array) {
    std::cout << "int8 array" << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int16Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Int64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt8Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt16Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::UInt64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::HalfFloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::FloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::DoubleArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::StringArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::BinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::FixedSizeBinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Date32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Date64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Time32Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Time64Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::TimestampArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::IntervalArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::Decimal128Array& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::ListArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK() &
        array.values()->Accept(this);
}
arrow::Status RArrayVisitor::Visit(const arrow::StructArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    auto ok = arrow::Status::OK();
    for (int ifield=0; ifield<array.num_fields(); ++ifield)
        ok &= array.field(ifield)->Accept(this);
    return arrow::Status::OK() & ok;

}
arrow::Status RArrayVisitor::Visit(const arrow::UnionArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}
arrow::Status RArrayVisitor::Visit(const arrow::DictionaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;
    return arrow::Status::OK();
}

}
