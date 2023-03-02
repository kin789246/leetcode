#include<iostream>
#include<vector>
#include<string>

using std::vector, std::string;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) return 1;
        int i=0, j=0;
        while (i<n) {
            int c=1;
            while (i<n-1 && chars[i]==chars[i+1]) {
                c++;
                i++;
            }
            chars[j++] = chars[i++];
            if (c > 1) {
                string str = std::to_string(c);
                for (char c : str) {
                    chars[j++] = c;
                }
            }
        }
        for (auto c : chars) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
        return j;
    }
    /*
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        int n=1;
        vector<char>::iterator i_c=chars.begin(), i_n=i_c+1;
        while (i_n != chars.end()) {
            if (*i_c == *i_n) {
                n++;
            }
            else {
                if (n>1) {
                    string str_n = std::to_string(n);
                    chars.erase(i_c+1, i_c+n);
                    i_n = i_c+1;
                    for (auto c : str_n) {
                        chars.emplace(i_n++, c);
                    }
                }
                i_c = i_n;
                n = 1;
            }
            i_n++;
        }
        if (i_c != chars.end()) {
            chars.erase(++i_c, chars.end());
        }
        if (n > 1) {
            for (auto c : std::to_string(n)) {
                chars.emplace_back(c);
            }
        }
        return (int)chars.size();
    }
    */
};

int main() {
    Solution solution;
    vector<char> chars1{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::cout << solution.compress(chars1)<< '\n';
    vector<char> chars2{'a', 'b', 'c'};
    std::cout << solution.compress(chars2) << '\n';
    vector<char> chars3{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    std::cout << solution.compress(chars3) << '\n';
    vector<char> chars4{ 'a', 'a', 'a', 'b', 'b', 'a', 'a' };
    std::cout << solution.compress(chars4) << '\n';
    return 0;
}

/*
443. String Compression

Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, 
be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.


Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

Constraints:
1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/