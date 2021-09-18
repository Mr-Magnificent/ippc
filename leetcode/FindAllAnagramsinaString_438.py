#%%
import collections

#%%
class Solution2:

    def findAnagrams(self, s: str, p: str) -> list[int]:
        p_map: dict = {}
        for letter in p:
            p_map[letter] = 1 if letter not in p_map else p_map[letter] + 1
        
        matched_count: int = 0
        ans: list[int] = []

        i: int = 0
        j: int = 0
        s_map: dict = {}
        while (j < len(p) and j < len(s)):
            if (s[j] in p_map):
                s_map[s[j]] = 1 if s[j] not in s_map else s_map[s[j]] + 1
                if (s_map[s[j]] <= p_map[s[j]]):
                    matched_count = matched_count + 1
                if (matched_count == len(p)):
                    ans.append(i)
            j += 1


        while (j < len(s)):
            if (s[i] in p_map):
                s_map[s[i]] = s_map[s[i]] - 1
                if (s_map[s[i]] < p_map[s[i]]):
                    matched_count -= 1

            i += 1

            if (s[j] in p_map):
                s_map[s[j]] = 1 if s[j] not in s_map else s_map[s[j]] + 1
                # print(s_map[s[j]] <= p_map[s[j]])
                # print(s_map, matched_count,i, j)
                if (s_map[s[j]] <= p_map[s[j]]):
                    matched_count = matched_count + 1 
                # print(s_map, matched_count,i, j)
                if (matched_count == len(p)):
                        ans.append(i)
            j += 1

        return ans


#%%
class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        ans: list = []

        if (len(s) < len(p)):
            return ans

        pmap = collections.Counter(p)
        smap = collections.Counter(s[:len(p)])

        i, j = 0, len(p)
        while(j < len(s)):
            if (pmap == smap):
                ans.append(i)

            smap[s[j]] += 1 
            smap[s[i]] = smap[s[i]] - 1
            if (smap[s[i]] == 0):
                smap.pop(s[i])

            i += 1
            j += 1

        print(pmap, smap)
        if (pmap == smap):
            ans.append(i)

        return ans


#%%
print(Solution().findAnagrams("baa", "aa"))


#%%
a = {"t": 1, "p": 2}
b = {"t": 1, "p": 3, 'd': 0}
print(a == b)


#%%
s, m = "sdfasdf", {}
print(s)
for letter in s:
    m[letter] = 1 if letter not in m else m[letter] + 1
print(m)
print(m.get('p'))
i = j = 10
print(i, j)
# %%
