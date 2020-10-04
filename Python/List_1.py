list = [1,2,3,4,5]
print(list)

list.append(6)
print(list)

list.insert(3,10)
print(list)

list.remove(10)
print(list)

print(5 in list)
print(50  in list)

print(f'{list.count(2)} times')

list.pop()
print(list)

print(list.index(4))

list.append(3)
list.append(30)
list.sort()
print(list)

list.reverse()
print(list)
print('3 count - > ',list.count(3))

list.clear()
print(list)