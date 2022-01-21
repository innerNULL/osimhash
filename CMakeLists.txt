# file: CMakeLists.txt
# date: 2022-01-20

 
cmake_minimum_required(VERSION 3.14)
project(osimhash)

include(FetchContent)
include(ExternalProject)

# No compiling optimization, very slow
#set(CMAKE_CXX_FLAGS "-fopenmp") 
# Compiling optimization params
set(CMAKE_CXX_FLAGS 
  "-fopenmp -pthread -std=c++14 -funroll-loops -O3 -march=native")


option(OSIMHASH_BENCHMARK "Benchmarking." ON)
option(OSIMHASH_PY_BIND "Builds python binder." ON)


set(FETCHCONTENT_QUIET FALSE)
set(GIT_HOST "ghproxy.com/https://github.com")


ExternalProject_Add(
  simhash
  PREFIX _exts 
  GIT_REPOSITORY https://${GIT_HOST}/yanyiwu/simhash.git  
  GIT_TAG master 
  CMAKE_ARGS 
      -DBENCHMARK=OFF 
      -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> 
  BUILD_COMMAND "" 
  INSTALL_COMMAND "")
ExternalProject_Get_Property(simhash source_dir)
include_directories(${source_dir}/include)
include_directories(${source_dir}/deps)


include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(benchmarks/cpp)
add_subdirectory(bindings/python)
