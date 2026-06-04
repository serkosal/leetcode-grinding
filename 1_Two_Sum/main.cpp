#include <iostream>
#include <vector>

#include "cpp_helpers/helpers.hpp"

using std::vector;

vector<int> twoSumNaive(const vector<int>&& nums, int target) {
    
    size_t sz = nums.size();

    // naive O(n^2)
    for (size_t i = 0; i < sz; ++i)
        for (size_t j = i + 1; j < sz; ++j) 
            if (nums[i] + nums[j] == target)
                return {int(i), int(j)};


    return {};
}

#include <algorithm>

vector<int> twoSum(const vector<int>& nums, int target) {

    // my soltution

    using indexedValue = std::pair<int, size_t>;
    auto sz = nums.size();

    // create mapping from sorted values to their previous indexes in nums vector 
    vector<indexedValue> v;
    for (size_t i = 0; i < sz; ++i)
        v.push_back({nums[i], i});

    // O(n * log n)
    std::sort(v.begin(), v.end(), 
        [](const indexedValue& a, const indexedValue& b) -> bool {
            return a.first < b.first;
        }
    );

    // find the target using left and right pointers O(n)
    auto l = v.begin(), r = v.end() - 1;
    while (l < r) {
        int sum = l->first + r->first;
        if (sum == target)
            // returning indexes before sorting
            return {int(l->second), int(r->second)}; 
        else if (sum < target)
            ++l;
        else
            --r;
    }

    return {};
}

#include <unordered_map>

vector<int> twoSumOptimal(const vector<int>& nums, int target) {

    // mapping 
    std::unordered_map<int, size_t> map;

    // average: O(n), worst case
    for (size_t i = 0; i < nums.size(); ++i)
        map[nums[i]] = i;

    // O(n)
    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end() && map[complement] != i )
            return {int(i), int(map[complement])};
    }

    return {};
}

int main() {

    print_container(twoSumOptimal( {2,7,11,15}, 9 ));
    print_container(twoSumOptimal( {3,2,4},     6 ));
    print_container(twoSumOptimal( {3,3},       6 ));

    return 0;
}