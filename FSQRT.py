# https://www.codechef.com/problems/FSQRT

import math
t=int(input())
for i in range(t):
    a=int(input())
    d=math.sqrt(a)
    b=d//1
    print(round(b))
