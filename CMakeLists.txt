# file: CMakeLists.txt
# date: 2022-01-20

 
cmake_minimum_required(VERSION 3.14)
project(osimhash)


# No compiling optimization, very slow
#set(CMAKE_CXX_FLAGS "-fopenmp") 
# Compiling optimization params
set(CMAKE_CXX_FLAGS 
  "-fopenmp -pthread -std=c++14 -funroll-loops -O3 -march=native")


option(BENCHMARK "Benchmarking." ON)
option(PYBIND "Builds python binder." ON)


include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)


FetchContent_Declare(
  yanyiwu_simhash 
  GIT_REPOSITORY https://github.com.cnpmjs.org/yanyiwu/simhash.git 
  GIT_TAG master 
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(yanyiwu_simhash)
include_directories(${yanyiwu_simhash_SOURCE_DIR}/deps)
include_directories(${yanyiwu_simhash_SOURCE_DIR}/include)


include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(benchmarks/cpp)
add_subdirectory(bindings/python)
