a = [5, 10, 15, 20, 25]
new=[]
def func(a):
    new=[]
    new.append(a[0])
    new.append(a[len(a)-1])
    return new

new = func(a)
print(new)

