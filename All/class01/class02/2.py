# https://www.lanqiao.cn/problems/3382/learning/?page=1&first_category_id=1&problem_id=3382
from itertools import accumulate

MOD = 1000000007


# 求出a的前缀和:
def get_presum(a):
    sum = list(accumulate(a))
    sum = [x % MOD for x in sum]
    return sum


# 快速求区间a[1]+...+a[r]之和
def get_sum(sum, l, r):
    if l == 0:
        return sum[r]
    else:
        return (sum[r] - sum[l - 1] + MOD) % MOD  # 可能为负数


n, m = map(int, input().split())
a = list(map(int, input().split()))

# 存储a数组的前缀和、a数组平方的前和、
sum_list = []
for i in range(1, 6):
    tmp_a = [x ** i for x in a]
    sum_list.append(get_presum(tmp_a))

for _ in range(m):
    l, r, k = map(int, input().split())
    print(get_sum(sum_list[k - 1], l - 1, r - 1))
