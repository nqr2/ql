cmake_minimum_required(VERSION 4.1.2)

project(
  "ql"
  LANGUAGES C
  VERSION 0.0.0
  HOMEPAGE_URL "https://github.com/nqr2/ql"
  DESCRIPTION "The questionable C library."
)

set(CMAKE_C_STANDARD 23 REQUIRED)
set(CMAKE_C_EXTENSIONS NO)

option(QL_BUILD_DOCS "Build the documentation with Doxygen" ON)
option(QL_BUILD_TESTS "Build the tests" ON)
option(QL_ENABLE_ASSERTS "Enable the QL_ASSERT macro" ON)
option(QL_ENABLE_LOG "Enable the QL_LOG macro" ON)

if(QL_BUILD_DOCS)
  add_subdirectory("doc")
endif()

add_library("ql"
  "include/ql/Allocator.h"
  "include/ql/Argparse.h"
  "include/ql/Array.h"
  "include/ql/Assert.h"
  "include/ql/Exn.h"
  "include/ql/Hash.h"
  "include/ql/Log.h"
  "include/ql/Number.h"
  "include/ql/Table.h"
  "include/ql/Tap.h"

  "src/Allocator.c"
  "src/Argparse.c"
  "src/Array.c"
  "src/Assert.c"
  "src/Exn.c"
  "src/Hash.c"
  "src/Log.c"
  "src/Number.c"
  "src/Table.c"
  "src/Tap.c"
)

target_include_directories("ql" PUBLIC "include")

add_library(ql::ql ALIAS "ql")

if(QL_BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory("tests")
endif()
