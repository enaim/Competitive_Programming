#include <stdio.h>
#include <string.h>
#include <math.h>

void sorTed(int n,int ar[])
{
  int i, j, temp;
        ///Bubble sort
       for(i = 0; i < n; i++)
           for(j = 0 ; j < n-1-i; j++)
              if(ar[j] > ar[j+1])
              {
                 temp = ar[j];
                 ar[j] = ar[j+1];
                 ar[j+1]= temp;
              }
}




int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x,n,i;
    int a[100];

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sorTed(n,a);

    for(i = 0; i < n; i++)
          printf("%d    ", a[i]);
       printf("\n");
    }

    return 0;
}

