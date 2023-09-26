#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<limits>
using std::string, std::vector, std::unordered_map;

class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> window, map_t;
        int have=0; 
        int need;
        int l=0;
        int res_len = std::numeric_limits<int>::max();
        std::pair<int, int> res{-1, -1};
        for (char c : t)
        {
            if (map_t.contains(c)) 
                map_t[c]++;
            else
                map_t[c]=1;
        }
        need=map_t.size();
        for (int r=0; r<s.length(); r++)
        {
            if (window.contains(s[r]))
                window[s[r]]++;
            else
                window[s[r]]=1;
            if (map_t.contains(s[r]) && window[s[r]] == map_t[s[r]])
                have++;
            while (have == need)
            {
                if ((r-l+1) < res_len)
                {
                    res = std::make_pair(l, r);
                    res_len = r-l+1;
                }
                if (window.contains(s[l]))
                {
                    window[s[l]]--;
                    if (window[s[l]] < 0)
                        window[s[l]]=0;
                }
                if (map_t.contains(s[l]) && window[s[l]] < map_t[s[l]])
                    have--;
                l++;
            }
        }
        return res_len == std::numeric_limits<int>::max() ? 
            "" : s.substr(res.first, res_len);
    }
private:
    // Helper lambda function to print key-value pairs
    void print_key_value(const auto& key, const auto& value) 
    {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    }
    void print(unordered_map<char, int> u)
    {
        for (const auto& [key, value] : u)
            print_key_value(key, value);
    }
};

int main() {
    Solution solution; 
    //string s{ "ADOBECODEBANC" }, t{ "ABC" }; 
    //string s{ "aa" }, t{ "aa" };
    string s{ "bbaa" }, t{ "aba" };
    std::cout << solution.minWindow(s, t) << '\n'; 
    return 0; 
} 

/* 
76. Minimum Window Substring 
Hard 
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) 
is included in the window. If there is no such substring, return the empty string "". 
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/