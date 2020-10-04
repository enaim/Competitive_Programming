#include <stdio.h>
#include <string.h>
#include <math.h>

void swapping(int n,int ar[])
{
  int i, j,S=0,temp;

    for(i = 0; i < n-1; i++)
        for(j = 0 ; j < n-1-i; j++)
            if(ar[j] > ar[j+1])
            {
                S++;
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1]= temp;
            }
    printf("Optimal train swapping takes %d swaps.\n",S);
}




int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x,L,i,r,N;
    int a[50];

    scanf("%d",&N);
    r=0;
    while(r<N)
    {
        scanf("%d",&L);
        for(i=0;i<L;i++)
            scanf("%d",&a[i]);

        swapping(L,a);

//    for(i = 0; i < n; i++)
//          printf("%d    ", a[i]);
//       printf("\n");
    r++;
    }

    return 0;
}

