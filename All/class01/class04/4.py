class Solution:
    def maxLengthOfList(self, nums, k):
        m = {0: -1}
        Sum, res = 0, 0
        for i, n in enumerate(nums):
            Sum += n
            if Sum not in m:
                m[Sum] = i
            if Sum - k in m:
                res = max(res, i-m[Sum-k])
        return res
n, k = map(int, input().split())
nums = list(map(int, input().split()))
obj = Solution()
print(obj.maxLengthOfList(nums, k))