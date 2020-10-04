#include <stdio.h>
#include <string.h>
#include <math.h>

void sortInd(int a,int b,int ar[])
{
  int i, j, temp;

       for(i = 0; i <= b-a; i++)
           for(j = a ; j <= b-i-1; j++)
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

    int a,b,n,i;
    int ar[100];

    while(3==scanf("%d%d%d",&n,&a,&b))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        sortInd(a,b,ar);

        for(i = a; i <= b; i++)
            printf("%4d", ar[i]);
        printf("\n");
    }

    return 0;
}

