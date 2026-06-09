#include "cpp_helpers/helpers.hpp"

int majorityElement(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> counts;
    for (const auto& el: nums)
        if (++counts[el] > n / 2)
            return el;

    return 0;
}

int main() {

    for (const auto& el: vector<vector<int>>{
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2}
    }) println("majority element for collection {} is {}", 
        el, majorityElement(el));

    return 0;
}