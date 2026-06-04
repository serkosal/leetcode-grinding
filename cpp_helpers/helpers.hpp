#pragma once

#ifndef LEETCODE_GRINDING_HELPERS
#define LEETCODE_GRINDING_HELPERS

#include <vector>
#include <ranges>

using V = std::vector<int>;

template <typename Container>
requires std::ranges::range<Container>
void print_container(const Container& c) {
    
    size_t sz = c.size();

    std::cout << "[";
    auto it = c.begin();

    if (sz) 
        std::cout << *(it++);
    
    for (; it < c.end(); ++it) 
        std::cout << ", " << *(it);

    std::cout << "]\n";
}

#endif