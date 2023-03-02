from typing import List

class Solution:
    def compress(self, chars: List[str]) -> int:
        sz = len(chars)
        if sz == 1: return 1
        i=0
        j=0
        while i < sz:
            c=1
            while i<sz-1 and chars[i]==chars[i+1]:
                c+=1
                i+=1
            chars[j] = chars[i]
            j+=1
            i+=1
            if c>1:
                s = str(c)
                for ch in s:
                    chars[j] = ch
                    j+=1
        return j

if __name__ == '__main__':
    s = Solution()
    chars1 = ["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
    #chars1 = ['a']
    print(s.compress(chars1))
    print(chars1)

