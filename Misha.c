#include "bloom_filter.h"
#include <stddef.h>

uint64_t calc_hash(const char* str, uint64_t modulus, uint64_t seed) {
  // TODO: Write any hash function for further usage
  uint64_t hash = seed;
  uint64_t base = 100;
  uint64_t power_of_base = 1;
  for (size_t i = 0; str[i] != '\0'; i++) {
    hash = (hash + (str[i] * power_of_base) % modulus) % modulus;
    power_of_base = (power_of_base * base) % modulus;
  }
  return hash;
}

void bloom_init(struct BloomFilter* bloom_filter, uint64_t set_size, hash_fn_t hash_fn, uint64_t hash_fn_count) {
  // TODO: Initialize bloom filter
  bloom_filter->set_size = set_size;
  bloom_filter->hash_fn = hash_fn;
  bloom_filter->hash_fn_count = hash_fn_count;
  bloom_filter->set = (uint64_t*)calloc((set_size + 63) / 64, sizeof(uint64_t));
}

void bloom_destroy(struct BloomFilter* bloom_filter) {
  // TODO: Free memory if needed
  free(bloom_filter->set);
  bloom_filter->set = NULL;
}

void bloom_insert(struct BloomFilter* bloom_filter, Key key) {
  // TODO: Insert key into set
  for (uint64_t i = 0; i < bloom_filter->hash_fn_count; ++i) {
    uint64_t modulus = 1000000007;
    uint64_t hash = bloom_filter->hash_fn(key, modulus, i) % bloom_filter->set_size;
    uint64_t hash_byte = hash / 64;
    uint64_t hash_bit = hash % 64;
    bloom_filter->set[hash_byte] |= ((uint64_t)1 << hash_bit);
  }
}

bool bloom_check(struct BloomFilter* bloom_filter, Key key) {
  // TODO: Check if key exists in set
  for (uint64_t i = 0; i < bloom_filter->hash_fn_count; ++i) {
    uint64_t modulus = 1000000007;
    uint64_t hash = bloom_filter->hash_fn(key, modulus, i) % bloom_filter->set_size;
    uint64_t hash_byte = hash / 64;
    uint64_t hash_bit = hash % 64;
    if (!(bloom_filter->set[hash_byte] & ((uint64_t)1 << hash_bit))) {
      return false;
    }
  }
  return true;
}
