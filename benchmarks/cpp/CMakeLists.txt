# file: CMakeLists.txt
# date: 2022-01-18


if(${CMAKE_VERSION} VERSION_GREATER "3.16.0" 
    AND ${OSIMHASH_BENCHMARK})
  message(
    STATUS 
    "CMake version is eligible for benchmarking and benchmarking flag is '${BENCHMARK}'.")
    
  include(FetchContent)
  set(FETCHCONTENT_QUIET FALSE)

  FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://${GIT_HOST}/google/benchmark.git 
    GIT_TAG v1.6.1
    GIT_PROGRESS TRUE)
  set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
  FetchContent_MakeAvailable(googlebenchmark)

  add_executable(
    benchmarking 
    ${PROJECT_SOURCE_DIR}/benchmarks/cpp/benchmarking.cpp)
  add_dependencies(benchmarking simhash)
  target_link_libraries(benchmarking benchmark::benchmark)
endif()
