#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<sstream>

using std::vector;
using std::string;
using std::set;
using std::map;
using std::stringstream;

void printSet(const char &key, const set<char> &set1) {
    std::cout << key << " -> ";
    for (auto& s : set1) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
}

class Solution {
public:
    int findX(vector<int> &v, int x) {
        if (v[x] == x) {
            return x;
        }
        v[x] = findX(v, v[x]);
        return v[x];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> table(26);
        for (int i=0; i<26; i++) {
            table[i] = i;
        }
        int len = s1.length();
        for (int i=0; i<len; ++i) {
            int a = findX(table, s1[i]-'a');
            int b = findX(table, s2[i]-'a');
            if (a < b) {
                table[b] = table[a];
            }
            if (a > b) {
                table[a] = table[b];
            }
        }

        for (int i=0; i<26; i++) {
            std::cout << char(table[i]+'a');
        }
        std::cout << '\n';

        for (char &c : baseStr) {
            c = char(findX(table, c-'a') + 'a');
        }

        return baseStr;
    }
};

int main() {
    Solution s;
    string s1 = "opecenadojbodihfgmpijpfocomhcncicefpohkibjckijghii";
    string s2 = "ndlbhpaeppgekfhnjnmmplmdoifdhbglmedpjgleofgnahglbe";
    string base = "ttusuhhrabgsswpaapxoxdanchyccmpjitwwmfioedtbiggfru";
    std::cout << s.smallestEquivalentString(s1,s2,base) << '\n';
    return 0;
}

/*
    Reflexivity: 'a' == 'a'.
    Symmetry: 'a' == 'b' implies 'b' == 'a'.
    Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
         s1 = "abc"
         s2 = "cde"
    baseStr = "eed"
    [a,c,e] [b,d]
    lexicographically smallest equivalent string = "aab"

         s1 = "parker"
         s2 = "morris"
    baseStr = "parser"
     output = "makkek"
     [m,p] [a,o] [k,r,s] [e,i]

         s1 = "hello"
         s2 = "world"
    baseStr = "hold"
     output = "hdld"
     [h,w] [d,e,o] [l,r]

         s1 = "leetcode"
         s2 = "programs"
    baseStr = "sourcecode"
     output = "aauaaaaada"
     [a,o,e,r,s,c] [l,p] [g,t] [d,m]

         s1 = "opecenadojbodihfgmpijpfocomhcncicefpohkibjckijghii"
         s2 = "ndlbhpaeppgekfhnjnmmplmdoifdhbglmedpjgleofgnahglbe"
    baseStr = "ttusuhhrabgsswpaapxoxdanchyccmpjitwwmfioedtbiggfru"
       Output "ttusubbraabsswbaabxbxdabbbybbbbbatwwbbabadtaabbbru"
     Expected "ttusuaaraaasswaaaaxaxaaaaayaaaaaatwwaaaaaataaaaaru"
*/