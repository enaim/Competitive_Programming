#include<stdio.h>


int main()
{
    int i,j,cnt=0;
    for(i=1;i<=10;i++)
    {
        for(j=i+1;j<=10;j++)
        {
            if(i*i + j*j <=100)
            {
                cnt++;
                printf("%d %d\n",i,j);
            }
        }
        printf("\n\n");
    }
    printf("%d\n",cnt);

    return 0;
}
