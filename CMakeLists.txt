cmake_minimum_required( VERSION 3.8 )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

project(VariatTest)

include( FindPkgConfig )

find_package( benchmark REQUIRED )
find_package( Boost REQUIRED )

add_executable( ${PROJECT_NAME}
  src/variant.cpp
)

include_directories( ${Boost_INCLUDE_DIR} )

target_link_libraries( ${PROJECT_NAME}
  PUBLIC
  pthread
  benchmark::benchmark
  benchmark::benchmark_main
  ${Boost_LIBRARIES}
)
