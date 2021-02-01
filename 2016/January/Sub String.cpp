#include<stdio.h>
#include<string.h>


int main()
{
    int l,i,n;
    char r[100];

    while(scanf("%s",r)==1)
    {
        n =strlen(r);

        for(l=1;l<=n;l++)
        {   printf("l: %d\n",l);
            for(i=0;i<n;i++)
            {   printf("i: %d\n",i);
                if(i+l-1<n)
                {   printf("i+l-1: %d\n",i+l-1);
                    for(int k=i;k<i+l;k++)

                        printf("%c",r[k]);
                    printf("\n");
                }
            }
        }
    }
}
