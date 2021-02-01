#include<stdio.h>
#include<string.h>


bool palenDrom(int a,int b,char c[])
{
    int i;

    for(i=a;i<=b;i++)
        printf("%c",c[i]);
    printf("\n");


    while(a<=b)
    {
        if(c[a]==c[b])
        {
             a++;
             b--;
        }
        else
            return false;
    }
    return true;
}


int main()
{
    int l,i,n,x;
    char r[100];

    while(scanf("%s",r)==1)
    {
        n =strlen(r);

        int mxl = 0;
        int mxs = 0;
        int mxe = 0;

        for(l=1;l<=n;l++)
        {
            for(i=0;i<n;i++)
            {   printf("i: %d\n",i);
                if(i+l-1<n)
                {   printf("i+l-1: %d\n",i+l-1);

                    x=palenDrom(i,i+l-1,r);

                    if(x==true)
                        {
                            if(mxl<l)
                                {
                                    mxl = l;
                                    mxs = i;
                                    mxe = i + l - 1;
                                }
                        }
                }
            }
        }
        printf("max srt ind = %d\nmax end ind = %d\n",mxs,mxe);
    }
}
