#include "cpp_helpers/helpers.hpp"

int searchInsert(const vector<int>& n, int target) {

    int l = 0, r = n.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;

        if (n[m] == target) return m;
        else if (n[m] < target)
            l = m + 1;
        else 
            r = m - 1;
    }

    if (n[l] >= target) return l;
    else return l + 1;
}

int main() {

    for (const auto& [target, vec]: vector<pair<int, vector<int>>>{
        {5, {1,3,5,6}},
        {2, {1,3,5,6}},
        {7, {1,3,5,6}}
    }) {
        println(
            "insert index of target = {} in {} is {}", 
            target,
            vec,
            searchInsert(vec, target)
        );
    }

    return 0;
} 