#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);


    int a ,b,n,m,i,cnt;

    while(2==scanf("%d%d",&n,&m))
    {
        cnt = 0;
        if(n>m)
        {
            for(i=0;i<n;i++)
            {
                printf("B");
                if(cnt!=m)
                {
                    printf("G");
                    cnt++;
                }
            }
        }
        else
        {
            for(i=0;i<m;i++)
            {
                printf("G");
                if(cnt!=n)
                {
                    printf("B");
                    cnt++;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
