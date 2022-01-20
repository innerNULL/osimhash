/// file: py_module.cpp
/// date: 2022-01-19


#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

#include <osimhash/osimhash.h>

namespace py = pybind11;
using namespace osimhash;


PYBIND11_MODULE(pyosimhash, m) {
  m.doc() = "python binding for yanyiwu/simhash.";

  m.def("keywords2simhash", &keywords2simhash);
  
  m.def("simhash2bin_str", &simhash2bin_str);
  
  m.def("bin_str2simhash", &bin_str2simhash);
  
  m.def("is_equal", 
      [](uint64_t lsh1, uint64_t lsh2) {
        return is_equal(lsh1, lsh2, 3); }); 
  m.def("is_equal", 
      [](uint64_t lsh1, uint64_t lsh2, uint8_t n) {
        return is_equal(lsh1, lsh2, n); }); 
  m.def("is_equal",
      [](std::string lsh1, std::string lsh2) {
        return is_equal(lsh1, lsh2, 3); });
  m.def("is_equal",
      [](std::string lsh1, std::string lsh2, uint8_t n) {
        return is_equal(lsh1, lsh2, n); });

  m.def("pairs_equal", 
      [](std::vector<uint64_t> simhashs) {
        return pairs_equal(simhashs, 3); });
  m.def("pairs_equal", 
      [](std::vector<uint64_t> simhashs, uint8_t n) {
        return pairs_equal(simhashs, n); });
  m.def("pairs_equal", 
      [](std::vector<std::string> simhashs) {
        return pairs_equal(simhashs, 3); });
  m.def("pairs_equal", 
      [](std::vector<std::string> simhashs, uint8_t n) {
        return pairs_equal(simhashs, n); });  
}
