#include<iostream>
#include<vector>
#include<string>

using std::vector, std::string;

class Solution {
private:
    void print(vector<int> v)
    {
        for (auto x : v)
        {
            std::cout << x << " ";
        }
        std::cout << '\n';
    }
    void debug_code(vector<int> &v1, vector<int> &v2)
    {
        for(int i=0; i<26; i++)
        {
            std::cout << char(i+'a') << ' ';
        }
        std::cout << '\n';
        print(v1);
        print(v2);
    }
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) return false;

        int match = 0;
        vector<int> s1_count(26), s2_count(26);
        for (int i=0; i<s1.size(); i++)
        {
            s1_count[int(s1[i]) - int('a')]++;
            s2_count[int(s2[i]) - int('a')]++;
        }        
        for (int i=0; i<26; i++)
        {
            if (s1_count[i] == s2_count[i])
            {
                match++;
            }
        }
        for (int i=s1.size(); i<s2.size(); i++)
        {
            if (match == 26) return true;
            int idx = int(s2[i]-'a');
            s2_count[idx]++;
            if (s2_count[idx] == s1_count[idx])
            {
                match++;
            }
            else if (s1_count[idx]+1 == s2_count[idx])
            {
                match--;
            }
            idx = int(s2[i-s1.size()]) - int('a');
            s2_count[idx]--;
            if (s2_count[idx] == s1_count[idx])
            {
                match++;
            }
            else if (s1_count[idx]-1 == s2_count[idx])
            {
                match--;
            }
        }
        return match == 26;
    }
};

int main() {
    string s1{ "ab" };
    string s2{ "eidbxaooo" };
    Solution s;
    if (s.checkInclusion(s1, s2))
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl;
    return 0;
}

/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/