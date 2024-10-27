#include "bloom_filter.h"
#include <stdlib.h>
#include <string.h>

uint64_t calc_hash(const char* str, uint64_t modulus, uint64_t seed) {
    // TODO: Write any hash function for further usage
    uint64_t hash = seed;
    uint64_t p = 107;
    uint64_t p_pow = 1;

    for (int i = 0; str[i] != '\0'; ++i) { 
        hash = (hash + (str[i] - 'a' + 1) * p_pow) % modulus;
        p_pow = (p_pow * p) % modulus;
    }
    
    return hash;
}

void bloom_init(struct BloomFilter* bloom_filter, uint64_t set_size, hash_fn_t hash_fn, uint64_t hash_fn_count) {
    // TODO: Initialize bloom filter
    bloom_filter->set_size = set_size;
    bloom_filter->hash_fn = hash_fn;
    bloom_filter->hash_fn_count = hash_fn_count;

    size_t array_size = (set_size + 63) / 64;
    bloom_filter->set = (uint64_t*)calloc(array_size, sizeof(uint64_t));
}

void bloom_destroy(struct BloomFilter* bloom_filter) {
    // TODO: Free memory if needed
    free(bloom_filter->set);
    bloom_filter->set = NULL;
}

void bloom_insert(struct BloomFilter* bloom_filter, Key key) {
    // TODO: Insert key into set
}

bool bloom_check(struct BloomFilter* bloom_filter, Key key) {
    // TODO: Check if key exists in set
}

