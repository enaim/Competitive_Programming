n = int(input())
ar=[]
for i in range(n):
    br=[]
    br = str(input()).split()
    ar.append(br)

for i in range(n):
    for j in range(n):
        print(f'{ar[i][j]}',end=" ")
    print("\n")