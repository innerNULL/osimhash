# file: CMakeLists.txt
# date: 2022-01-18


if(${CMAKE_VERSION} VERSION_GREATER "3.16.0" 
    AND ${OSIMHASH_PY_BIND})
  message(
    STATUS
    "CMake version is eligible for py-binding and py-binding flag is '${PYBIND}'.")

  include(FetchContent)
  set(FETCHCONTENT_QUIET FALSE)

  FetchContent_Declare(
    pybind_pybind11
    GIT_REPOSITORY https://${GIT_HOST}/pybind/pybind11.git 
    GIT_TAG v2.9.0 
    GIT_PROGRESS TRUE)
  FetchContent_MakeAvailable(pybind_pybind11)
    
  message(
    STATUS 
    "Py-module located at '${PROJECT_SOURCE_DIR}/bindings/python/pymodule.cpp'.")
  message(STATUS "PYTHON_EXECUTABLE=${PYTHON_EXECUTABLE}")

  pybind11_add_module(
    pyosimhash ${PROJECT_SOURCE_DIR}/bindings/python/pymodule.cpp)
  add_dependencies(pyosimhash simhash)
endif()
