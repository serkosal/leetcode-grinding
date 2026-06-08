#include "cpp_helpers/helpers.hpp"

std::unordered_map<string_view, bool> cache;
bool check_palindrome_rec(string_view s) {

    if (s.size() <= 1) return true;
    if (cache.contains(s)) return cache[s];
    else return cache[s] = (s.front() == s.back() && 
        check_palindrome_rec({s.begin() + 1, s.end() - 1})
    );
}

string longestPalindromeRec(const string& s) {
    cache.clear();

    size_t sz = s.size();
    for (size_t max_start = 0; max_start < sz; ++max_start) {
        for (size_t start = 0; start <= max_start; ++start) {
            string_view t = {s.begin() + start, s.end() - (max_start - start)};
            if (check_palindrome_rec(t))
                return string(t);
        }
    }

    return "";
}

string longestPalindrome(const string& s) {
    string_view res = "";

    auto expand = [&s](string::const_iterator l, string::const_iterator r) {

        using std::next, std::prev;
        while ( 
            prev(l) >= s.begin() 
         && next(r)  < s.end()
         && *prev(l) == *next(r)
        ) --l, ++r;

        return string_view{l, r+1};
    };
    auto end = s.begin() + s.size() / 2;
    for (auto it = s.begin(); it < s.end(); ++it) {
        string_view t = expand(it, it);
        if (t.size() > res.size()) res = t;
        
        if (it + 1 < s.end() && *it == *(it + 1)) {
            t = expand(it, it + 1);
            if (t.size() > res.size()) res = t;
        }
    }

    return string{res};
}

int main() {
    vector<string> s = {
        "abb",
        "abaxycdcz",
        "pihoigwlvzvtrugdolvtzrkyelaqdvbijzmkhebzawboaxkdjyfocpewwztffuaibcqurwwmijmvrnpfcoglyxpxkrbhupoxcafabxtoecodsjgngrionuvzaiigevuvruxxiwpjzjlqgenglhprcgzgpdzabrjhkbtfrbmwpcszepxhwiwdhvnpsmhhaiqsbeiwsaeomqtzcpjzfknejxlxwtpkufanhuoyjgihdzhtxnyctazzvnttjspfztjurdwmmzrvobcatkorfhpieoqfetcglembkgbexsznuduhrfoxkbswkanqwfkoktnnujqetijaqhrxuhkgsezfdrncbaltctwcourdbpdwhqlsxfwsoaduaqkbjeekwwykptjthhtokrvzsuelsywyznqscnwiszogzqvfsgggzltlvzkllinpfaigswquqfvabbzvestwxhbnfjhnvfhyxalchmtkcwnyyrbwjsoqooypwteozbivqiyldpqlykxinmzkgnmfbobgjivlzubfen",
        "xaabacxcabaax",
        "aaabaaaa",
        "abbcccba",
        
        "qwertyuiopasdfghjklzxcvbnm",
        "ac",
        "a",
        "",
    };
    for (const auto& el : s)
        println("longest palindrome for '{}' is '{}'", el, longestPalindrome(el));

    return 0;
}