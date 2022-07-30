import math

temp= input().split()
x, y = int(temp[0]), int(temp[1])

y = 26**y

r = x*1.0 / y

if r<=1:
    print(1)
else:
    print(math.ceil(math.log10(r)))