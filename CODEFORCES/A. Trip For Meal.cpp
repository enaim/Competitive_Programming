#include<stdio.h>


int main()
{
    int a,b,c,n,ans,x;
    while(1==scanf("%d",&n))
    {
        ans = 0;
        scanf("%d%d%d",&a,&b,&c);
        if(n==1)
            printf("0\n");
        else
        {
            x = 0;
            if(a<b)
            {
                ans+=a;
                x = 1;
            }
            else
                ans+=b;

            if(x && n>2)
            {
                if(a<c)
                {
                    ans+=a;
                    ans+=(n-3)*a;
                }
                else
                {
                    ans+=c;
                    ans+=(n-3)*c;
                }

            }
            else if(n>2)
            {
                if(b<c)
                {
                    ans+=b;
                    ans+=(n-3)*b;
                }
                else
                {
                    ans+=c;
                    ans+=(n-3)*c;
                }
            }
            printf("%d\n",ans);
        }
    }

    return 0;

}
