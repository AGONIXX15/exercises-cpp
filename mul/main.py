



# def fibo(n: int) -> int:
#     a: int = 0
#     b: int = 1



#     if n == 0:
#         return 0
#     if n == 1:
#         return 1

#     for i in range(n):
#         c: int = a + b

#         a = b
#         b = c

#     return a


#a0 = 0
# a1 = 1

# an = an-1 + an-2

# r² = r + 1
# r² -r -1 = 0
# (-b +|- sqrt(b²-4ac))/2a

# r0 = (1 + sqrt(5))/2
# r1 = (1 - sqrt(5))/2

# an = r0^n*A + r1^n * B
# 0 = A + B
# 1 = r0¹*A + r1 * B

# A = -B
# 1 = (1+ sqrt(5))/2) * -B + r1 * B
# 1 = B((-1 -sqrt(5))/2 + (1 - sqrt(5))/2)
# 1 = B(-sqrt(5))

# 1/-sqrt(5) = B
# 1/sqrt(5) = A

# an = r0^n*A + r1^n*B

import math
r0 = (1 + math.sqrt(5))/2
r1 = (1 - math.sqrt(5))/2
a = 1/math.sqrt(5)
b = 1/-math.sqrt(5)

n: int = int(input("ingrese un n para calcular el numero de fibo: "))

an = (r0 ** n) *a + (r1**n) * b

print(an)



