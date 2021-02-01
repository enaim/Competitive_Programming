n = int(input())

p = int(1);
for i in range(2,n):
    if n%i==0:
        p = 0;

if p==1:
    print("Prime")

else:
    print("Not Prime")

