#include<stdio.h>
#include<math.h>


int main()
{
    int i,sum,n;

    scanf("%d",&n);

    sum=0;

    for(i=1;i<=n;i=i+1)

    sum =sum + pow(i,2);

    printf("sum -> %d",sum);
    return 0;
}
