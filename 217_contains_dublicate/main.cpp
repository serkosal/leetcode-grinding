#include "cpp_helpers/helpers.hpp"

bool containsDuplicate(const vector<int>& nums) {
    unordered_map<int, int> seen;

    for (int num : nums )
        if (++seen[num] > 1) 
            return true;

    return false;
}

int main() {

    for (const auto& vec: vector<vector<int>>{
        {1,2,3,1},
        {1,2,3,4},
        {1,1,1,3,3,4,3,2,4,2}
    }) {
        bool contains_dublicates = containsDuplicate(vec);
        println(
            "{}, array = {} {} dublicates", 
            contains_dublicates ? "Yes" : "No",
            vec,
            contains_dublicates ? "contains" : "doesn't contain"
        );
    }

    return 0;
}