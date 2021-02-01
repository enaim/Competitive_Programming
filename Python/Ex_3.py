a = [1,2,3,4,5,6,7,8,9,10]

num = int(input("Enter a number -> "))

new = []

for i in a:
    if i<num:
        new.append(i)

print(new)

