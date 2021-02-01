#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,j,x;
    char name[20][50];
    char temp[20];

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%s",name[i]);

        for(i = 0; i < n; i++)
            for(j = 0 ; j < n-1-i; j++)
            {
                x=strcmp(name[j],name[j+1]);
                if(0<x)
                {
                    strcpy(temp,name[j]);
                    strcpy(name[j],name[j+1]);
                    strcpy(name[j+1],temp);
                }
            }
        printf("\n");

        for(i=0;i<n;i++)
            printf("%s\n",name[i]);
        printf("\n");
    }

    return 0;
}


