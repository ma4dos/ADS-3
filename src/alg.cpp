// Copyright 2025 NNTU-CS
#include <cstdint>
#include <unordered_map>
#include <algorithm>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  static std::unordered_map<uint64_t, uint64_t> cache;
  if (num == 1) return 1;
  auto it = cache.find(num);
  if (it != cache.end()) return it->second;
  uint64_t next = (num % 2 == 0) ? num / 2 : 3 * num + 1;
  uint64_t maxVal = std::max(num, collatzMaxValue(next));
  cache[num] = maxVal;
  return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  static std::unordered_map<uint64_t, unsigned int> cache;
  if (num == 1) return 1;
  auto it = cache.find(num);
  if (it != cache.end()) return it->second;
  uint64_t next = (num % 2 == 0) ? num / 2 : 3 * num + 1;
  unsigned int len = 1 + collatzLen(next);
  cache[num] = len;
  return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int bestLen = 0;
  uint64_t bestNum = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int len = collatzLen(i);
    if (len > bestLen) {
      bestLen = len;
      bestNum = i;
    }
  }
  *maxlen = bestLen;
  return bestNum;
}
