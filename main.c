#include "bloom_filter.h"

uint64_t calc_hash(const char* str, uint64_t modulus, uint64_t seed) {
    // TODO: Write any hash function for further usage
    uint64_t hash = seed; // Начальное значение хэша
    uint64_t p = 107;      // Основание полинома
    uint64_t p_pow = 1;   // p^i, начальное значение равно 1 (p^0)

    for (int i = 0; str[i] != '\0'; ++i) { 
        hash = (hash + (str[i] - 'a' + 1) * p_pow) % modulus; // добавляем хэш символа
        p_pow = (p_pow * p) % modulus; // обновляем p^i
    }
    
    return hash;
}

void bloom_init(struct BloomFilter* bloom_filter, uint64_t set_size, hash_fn_t hash_fn, uint64_t hash_fn_count) {
    // TODO: Initialize bloom filter
    
}

void bloom_destroy(struct BloomFilter* bloom_filter) {
    // TODO: Free memory if needed
}

void bloom_insert(struct BloomFilter* bloom_filter, Key key) {
    // TODO: Insert key into set
}

bool bloom_check(struct BloomFilter* bloom_filter, Key key) {
    // TODO: Check if key exists in set
}

