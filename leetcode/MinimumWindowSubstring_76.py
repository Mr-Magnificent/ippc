import collections
import math

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tmap: collections.Counter = collections.Counter(t)
        smap = collections.Counter()
        i: int = 0
        j: int = 0

        min_win: int = math.inf
        min_i: int = 0
        matched_count: int = 0

        while (j < len(s)):
            smap[s[j]] += 1
            if (smap[s[j]] <= tmap[s[j]]):
                matched_count += 1


            while (matched_count == len(t)):
                if (j - i + 1 < min_win):
                    min_win = j - i + 1
                    min_i = i
                smap[s[i]] -= 1
                if (smap[s[i]] < tmap[s[i]]):
                    matched_count -= 1
                i += 1

            j += 1

        return s[min_i:min_i + (0 if min_win == math.inf else min_win)]


#%%
d1 = {'a': 1, 'b': 2}
d2 = {'a':1, 'b': 3, 'c':4}

print(d2.get('a'))

print(type(d1.keys() & d2.keys()))
print(type(d1.keys()))
# %%
