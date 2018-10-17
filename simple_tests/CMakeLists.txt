add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world)

add_executable(test_simple_builder test_simple_builder.cpp)
target_link_libraries(test_simple_builder ${ARROW_SHARED_LIB})

add_executable(test_row_builder test_row_builder.cpp)
target_link_libraries(test_row_builder ${ARROW_SHARED_LIB})
