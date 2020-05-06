'''
Problem Name: Candy Lottery
Problem Link: https://cses.fi/problemset/task/1727
Author: Sachin Srivastava (mrsac7)
'''
n, k = list(map(int, input().split()))
s = 0
d = k**n
for i in range(k):
    s += i**n
print('%.6f' %(k - s/d)) 
