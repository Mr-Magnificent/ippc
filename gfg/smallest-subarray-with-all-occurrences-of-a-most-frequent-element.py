#%%
import collections

class Solution:
    def smallestSubsegment (self, arr: list,  n) : 
        c: collections.Counter = collections.Counter(arr)
        ele: int = c.most_common()[0][0]
        
        return arr[arr.index(ele):len(arr) - arr[::-1].index(ele)]


# %%
a = [2,4,2,1,2,3,2,2,2,5,5,5,5,5,5]
t = filter(lambda x: collections.Counter(a).most_common()[0][1] == x[1], collections.Counter(a).most_common())
m = map(lambda x: ((len(a) - a[::-1].index(x[0])) - a.index(x[0]), p), t)
print((list(m)))
# %%
# for p in collections.Counter(a).most_common():
#     print(p)# for p in collections.Counter(a).most_common():
#     print(p)

#%%
print(Solution().smallestSubsegment(a, len(a)))
