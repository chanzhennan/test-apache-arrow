#include <iostream>

#include "RVisitors.hpp"
#include "RArrowInterface.hpp"

namespace ROOT {

RLinkBuilderVisitor::RLinkBuilderVisitor(RArrowInterface &interface)
    : interface{interface} 
{}

arrow::Status RLinkBuilderVisitor::Visit(const arrow::NullArray& array) {
    std::cout << "null array visit" << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::BooleanArray& array) {
    std::cout << "bool array" << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Int8Array& array) {
    std::cout << "int8 array" << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Int16Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Int32Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;

    // create a record for this node
//    auto record = new RLinkRecord{interface.dir};
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Int64Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::UInt8Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::UInt16Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::UInt32Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::UInt64Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::HalfFloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::FloatArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::DoubleArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::StringArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::BinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::FixedSizeBinaryArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Date32Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Date64Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Time32Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Time64Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::TimestampArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::IntervalArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::Decimal128Array& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the link
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;
    
    return arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::ListArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the node
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;

    // add a child and traverse
    current_link->children.push_back({});
    interface.current_link = &interface.current_link->children[0];
    auto res = array.values()->Accept(this);

    // set the link back
    interface.current_link = current_link;
    return res & arrow::Status::OK();
}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::StructArray& array) {
    std::cout << array.type()->ToString() << std::endl;

    // populate the node
    auto current_link = interface.current_link;
    current_link->atype_name = array.type()->name();
    current_link->record_position = -1;

    // add children and traverse each
    auto ok = arrow::Status::OK();
    int ifield = 0;
    current_link->children.resize(array.num_fields());
    for (auto &child : current_link->children) {
        interface.current_link = &child;
        ok &= array.field(ifield)->Accept(this);
        ++ifield;
    }

    // set the link back
    interface.current_link = current_link;
    return arrow::Status::OK() & ok;

}
arrow::Status RLinkBuilderVisitor::Visit(const arrow::UnionArray& array) {
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
