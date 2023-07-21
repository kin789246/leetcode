#include<iostream>
#include<string>
#include<vector>

using std::string, std::vector;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_map[26];
        for (int i=0; i<26; i++) {
            order_map[order[i]-'a'] = i;
        }

        for (size_t i=0; i<words.size()-1; i++) {
            int cur=0;
            while (words[i][cur] != '\0') {
                if (cur >= int(words[i + 1].length())) return false;
                if (order_map[words[i][cur] - 'a'] < order_map[words[i + 1][cur] - 'a']) break;
                if (order_map[words[i][cur] - 'a'] > order_map[words[i + 1][cur] - 'a']) return false;
                cur++;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<string> w1{ "hello","leetcode" };
    string o1{ "hlabcdefgijkmnopqrstuvwxyz" };
    std::cout << solution.isAlienSorted(w1,o1) << '\n';

    vector<string> w2{ "word","world","row" };
    string o2{ "worldabcefghijkmnpqstuvxyz" };
    std::cout << solution.isAlienSorted(w2, o2) << '\n';

    vector<string> w3{ "apple","app" };
    string o3{ "abcdefghijklmnopqrstuvwxyz" };
    std::cout << solution.isAlienSorted(w3, o3) << '\n';

    vector<string> w4{ "l","h" };
    string o4{ "xkbwnqozvterhpjifgualycmds" };
    std::cout << solution.isAlienSorted(w4, o4) << '\n';

    return 0;
}

/*
953. Verifying an Alien Dictionary
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

0 1 2 3 4 5 6 7 8 9
a b c d e f g h i j
k l m n o p q r s t
u v w x y z

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/