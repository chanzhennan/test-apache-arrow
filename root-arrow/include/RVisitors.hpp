#ifndef RArrayVisitor_h
#define RArrayVisitor_h

#include "arrow/visitor.h"
#include "arrow/array.h"

namespace ROOT {

class RLinkBuilderVisitor : public arrow::ArrayVisitor {
public:
    RLinkBuilderVisitor(RArrowInterface const&);
    ~RLinkBuilderVisitor() = default;

    arrow::Status Visit(const arrow::NullArray& array) override;
    arrow::Status Visit(const arrow::BooleanArray& array) override;
    arrow::Status Visit(const arrow::Int8Array& array) override;
    arrow::Status Visit(const arrow::Int16Array& array) override;
    arrow::Status Visit(const arrow::Int32Array& array) override;
    arrow::Status Visit(const arrow::Int64Array& array) override;
    arrow::Status Visit(const arrow::UInt8Array& array) override;
    arrow::Status Visit(const arrow::UInt16Array& array) override;
    arrow::Status Visit(const arrow::UInt32Array& array) override;
    arrow::Status Visit(const arrow::UInt64Array& array) override;
    arrow::Status Visit(const arrow::HalfFloatArray& array) override;
    arrow::Status Visit(const arrow::FloatArray& array) override;
    arrow::Status Visit(const arrow::DoubleArray& array) override;
    arrow::Status Visit(const arrow::StringArray& array) override;
    arrow::Status Visit(const arrow::BinaryArray& array) override;
    arrow::Status Visit(const arrow::FixedSizeBinaryArray& array) override;
    arrow::Status Visit(const arrow::Date32Array& array) override;
    arrow::Status Visit(const arrow::Date64Array& array) override;
    arrow::Status Visit(const arrow::Time32Array& array) override;
    arrow::Status Visit(const arrow::Time64Array& array) override;
    arrow::Status Visit(const arrow::TimestampArray& array) override;
    arrow::Status Visit(const arrow::IntervalArray& array) override;
    arrow::Status Visit(const arrow::Decimal128Array& array) override;
    arrow::Status Visit(const arrow::ListArray& array) override;
    arrow::Status Visit(const arrow::StructArray& array) override;
    arrow::Status Visit(const arrow::UnionArray& array) override;
    arrow::Status Visit(const arrow::DictionaryArray& array) override;

private:
    RArrowInterface const& interface;
};

class RArrayVisitor : public arrow::ArrayVisitor {
public:
    ~RArrayVisitor() = default;

    arrow::Status Visit(const arrow::NullArray& array) override;
    arrow::Status Visit(const arrow::BooleanArray& array) override;
    arrow::Status Visit(const arrow::Int8Array& array) override;
    arrow::Status Visit(const arrow::Int16Array& array) override;
    arrow::Status Visit(const arrow::Int32Array& array) override;
    arrow::Status Visit(const arrow::Int64Array& array) override;
    arrow::Status Visit(const arrow::UInt8Array& array) override;
    arrow::Status Visit(const arrow::UInt16Array& array) override;
    arrow::Status Visit(const arrow::UInt32Array& array) override;
    arrow::Status Visit(const arrow::UInt64Array& array) override;
    arrow::Status Visit(const arrow::HalfFloatArray& array) override;
    arrow::Status Visit(const arrow::FloatArray& array) override;
    arrow::Status Visit(const arrow::DoubleArray& array) override;
    arrow::Status Visit(const arrow::StringArray& array) override;
    arrow::Status Visit(const arrow::BinaryArray& array) override;
    arrow::Status Visit(const arrow::FixedSizeBinaryArray& array) override;
    arrow::Status Visit(const arrow::Date32Array& array) override;
    arrow::Status Visit(const arrow::Date64Array& array) override;
    arrow::Status Visit(const arrow::Time32Array& array) override;
    arrow::Status Visit(const arrow::Time64Array& array) override;
    arrow::Status Visit(const arrow::TimestampArray& array) override;
    arrow::Status Visit(const arrow::IntervalArray& array) override;
    arrow::Status Visit(const arrow::Decimal128Array& array) override;
    arrow::Status Visit(const arrow::ListArray& array) override;
    arrow::Status Visit(const arrow::StructArray& array) override;
    arrow::Status Visit(const arrow::UnionArray& array) override;
    arrow::Status Visit(const arrow::DictionaryArray& array) override;
};

}

#endif // RArrayVisitor_h
