#include "cpp_helpers/helpers.hpp"

int lengthOfLongestSubstring(const string& str) {
    int sz = str.size();
    int max_size = 0;
        
    for (int left = 0; left < sz - max_size; ) {

        int right = std::min(sz, left + 100);

        map<char, int> char_map;

        while (left < right) {
            char ch = str[left];
            if (char_map.contains(ch)) {
                left = char_map[ch] + 1; 
                break;
            }

            char_map[ch] = left++;
        }

        if (char_map.size() > max_size)
            max_size = char_map.size();
    }

    return max_size;
}

int main() {

    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << "\n";

    return 0;
}