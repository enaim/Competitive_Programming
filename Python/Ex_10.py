import random
a = random.sample(range(1,30), 12)
b = random.sample(range(1,30), 16)
print(a)
print(b)
result = [i for i in set(a) if i in b]
print(result)

