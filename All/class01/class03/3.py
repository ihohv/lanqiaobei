# https://www.lanqiao.cn/problems/3291/learning/?page=1&first_category_id=1&problem_id=3291
import os
import sys
# 请在此输入您的代码
while True:
  try:
    n, m = map(int, input().split())
    a = list(map(int, input().split())) # 数据是从a1开始读入，放在a[0],所以a[]里有 n - 1 个元素

    # 处理差分数组
    diff = [0] * (n + 1)
    diff[0] = a[0]
    for i in range(1, n): # a 里只有 n - 1 个元素，所以只循环到 n - 1 即可
      diff[i] = a[i] - a[i - 1]

    # 对每个区间进行加法， 也就是对差分数组的 l 后面的数字和 r 后面的数字进行操作
    for _ in range(m):
      x, y, z = map(int, input().split())
      x -= 1
      y -= 1  # 由于题目的数据是从 a1 开始，所以读入的区间跟着减一，同步
      diff[x] += z
      diff[y + 1] -= z
    
    # 把差分数组还原成前缀和数组，赋值给a数组
    a[0] = diff[0]
    for i in range(1, n):
      a[i] = a[i - 1] + diff[i]

    print(' '.join(map(str, a)))

  except:
    break