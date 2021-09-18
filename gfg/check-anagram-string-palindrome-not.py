import collections
class Solution:
    def isPossible(self, S) -> bool:
        smap = collections.Counter(S)

        odd = 0
        for key in smap:
            if (smap[key] % 2 == 1):
                odd += 1
        
        return odd == 1 or odd == 0

print(Solution().isPossible("geeksforgeeks"))