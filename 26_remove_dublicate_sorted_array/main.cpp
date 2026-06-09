#include "cpp_helpers/helpers.hpp"

int removeDuplicates(vector<int>& n) {
    for (int i = 0; i < n.size(); ++i)
    {
        int d_end = i + 1;
        while (d_end < n.size() && n[i] == n[d_end])
            ++d_end;

        int d_start = i + 1;
        int d_size = d_end - d_start;
        if (d_size) {
            for (; d_start < d_end; ++d_start)
                for (int d_cur = d_start; d_cur + d_size < n.size(); d_cur += d_size)
                    n[d_cur] = n[d_cur + d_size];

            n.resize(n.size() - d_size);
        }

    }

    return n.size();
}

int main() {

    for (auto& el: vector<vector<int>>{
        {1,1,2},
        {0,0,1,1,1,2,2,3,3,4}
    }) {
        print("before: {} ", el);
        removeDuplicates(el);
        println("after {}", el);
    }

    return 0;
}