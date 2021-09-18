#%%
import collections

class Solution:
    def longestUniqueSubsttr(self, S):
        # code here
        i: int = 0
        j: int = 0
        c: collections.Counter = collections.Counter()

        max_i: int = 0
        max_win: int = 0

        while (j < len(S)):
            c[S[j]] += 1

            while (c[S[j]] >= 2):
                c[S[i]] -= 1
                i += 1
            
            if (j - i + 1 > max_win):
                max_win = j - i + 1
                max_i = i
            j += 1

        return S[max_i: max_i + max_win]

#%%
print(Solution().longestUniqueSubsttr("geeksforgeeks"))
# %%
