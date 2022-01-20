/// file: osimhash.h
/// date: 2022-01-20


#ifndef __OSIMHASH_OVERSIMHASHER_H__
#define __OSIMHASH_OVERSIMHASHER_H__


#include <vector>
#include <string>
#include <utility>
#include <simhash/Simhasher.hpp>


namespace osimhash {


uint64_t keywords2simhash(
    const std::vector<std::pair<std::string, double> >& keywords) {
  return simhash::Simhasher::make_from_predefined_keywords(
      keywords);
}


std::string simhash2bin_str(uint64_t simhash) {
  std::string bin_str = "";
  simhash::Simhasher::toBinaryString(simhash, bin_str);
  return bin_str;
}


uint64_t bin_str2simhash(std::string bin_str) {
  return simhash::Simhasher::binaryStringToUint64(bin_str);
}


bool is_equal(
    uint64_t lsh1, uint64_t lsh2, uint8_t n=3) {
  return simhash::Simhasher::isEqual(lsh1, lsh2, n);
}


bool is_equal(
    std::string lsh1, std::string lsh2, uint8_t n=3) {
  return is_equal(
      bin_str2simhash(lsh1), bin_str2simhash(lsh2), n);
}


std::vector<std::vector<bool> > pairs_equal(
    std::vector<uint64_t> simhashs, uint8_t n=3) {
  int32_t count = simhashs.size();
  std::vector<std::vector<bool> >* results = 
      new std::vector<std::vector<bool> >(
        count, std::vector<bool>(count, 1));

  for (int32_t i = 0; i < count - 1; ++i) {
    for (int32_t j = i + 1; j < count; ++j) {
      (*results)[i][j] = is_equal(simhashs[i], simhashs[j], n);
      (*results)[j][i] = (*results)[i][j];
    }
  }
  return *results;
}


std::vector<std::vector<bool> > pairs_equal(
    std::vector<std::string> simhashs, uint8_t n=3) {
  std::vector<uint64_t> simhashs_(simhashs.size());
  for (int32_t i = 0; i < simhashs.size(); ++i) {
    simhashs_[i] = bin_str2simhash(simhashs[i]);
  }
  return pairs_equal(simhashs_, n);
}


} // namespace osimhash


#endif

