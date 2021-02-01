import random

numlist = []
list_length = random.randint(5, 15)

while len(numlist) < list_length:
    numlist.append(random.randint(1, 75))

evenlist = [i for i in numlist if i % 2 == 0]

print(numlist)
print(evenlist)

