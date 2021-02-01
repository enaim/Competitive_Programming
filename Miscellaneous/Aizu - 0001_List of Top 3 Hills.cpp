#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[10];
    int i,j,temp;

    for(i=0;i<10;i++)
        scanf("%d",&ar[i]);

     for(i = 0; i < 10; i++)
       for(j = 0 ; j < 10-1-i; j++)
          if(ar[j] > ar[j+1])
          {
             temp = ar[j];
             ar[j] = ar[j+1];
             ar[j+1]= temp;
          }

    for(i=9;i>6;i--)
        printf("%d\n",ar[i]);

    return 0;
}
