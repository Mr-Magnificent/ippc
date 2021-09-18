import collections
import math

class Solution:
    def gethash(self, st: str) -> str:
        lst: list = [0] * 26
        for ch in st:
            lst[ord(ch) - ord('a')] += 1

        ans = ""
        for val in lst:
            ans = ans + str(val) + "_"

        return ans

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp: dict = {}

        for string in strs:
            
            hash = self.gethash(string)

            if (mp.get(hash) == None):
                mp[hash] = [string]
            else:
                mp[hash].append(string)
        
        return mp.values()


#%%
st = "ASDSFS"

for s in st:
    print(s)
# %%
print(ord('b') - 97)
# %%
for i in [4,5,3,2,43]:
    print(i)
# %%
print(str(2))
# %%
