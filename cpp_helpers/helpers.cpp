#include "helpers.hpp"

#include <iostream>

void print_vec(const V& v) {

    size_t sz = v.size();

    std::cout << "[";
    
    if (sz) 
        std::cout << v[0];
    
    for (size_t i = 1; i < sz; ++i) 
        std::cout << ", " << v[i];

    std::cout << "]\n";
}