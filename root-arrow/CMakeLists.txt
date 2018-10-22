message("compiling root-arrow")

# add include folder to the include path
include_directories(${PROJECT_SOURCE_DIR}/root-arrow/include)

# setup root
find_package(ROOT REQUIRED COMPONENTS RIO)
message("*** ROOT_USE_FILE = ${ROOT_USE_FILE} ***")
include(${ROOT_USE_FILE})
if (ROOT_FOUND)
    message("*** ROOT is found with libraries ${ROOT_LIBRARIES} ***")
    include_directories("${ROOT_INCLUDE_DIRS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
elseif()
    message("*** root is not installed. root-arrow will not be built ***")
endif()

# only if root is present
if (ROOT_FOUND)
    # generate dictionaries with rootcling
    ROOT_GENERATE_DICTIONARY(G__RArrowInterfaceDictionaries
        ${PROJECT_SOURCE_DIR}/root-arrow/src/RArrowInterface.cpp
        LINKDEF ${PROJECT_SOURCE_DIR}/root-arrow/LinkDef.h
    )
    add_library(RArrowDictionaries SHARED G__RArrowInterfaceDictionaries.cxx)
    target_link_libraries(RArrowDictionaries ${ROOT_LIBRARIES})

    # compile library
    file (GLOB SOURCES src/*.cpp)
    add_library(root_arrow SHARED ${SOURCES})
    target_link_libraries(root_arrow ${ROOT_LIBRARIES} RArrowDictionaries ${ARROW_SHARED_LIB})

    # compile tests
    file (GLOB TESTS tests/*.cpp)
    foreach (TEST_SOURCE ${TESTS})
        string(REPLACE ".cpp" "" TEST ${TEST_SOURCE})
        get_filename_component(TEST ${TEST} NAME)
        add_executable(${TEST} ${TEST_SOURCE})
        target_link_libraries(${TEST} ${ROOT_LIBRARIES} ${ARROW_SHARED_LIB} root_arrow)
    endforeach(TEST_SOURCE)
endif()
