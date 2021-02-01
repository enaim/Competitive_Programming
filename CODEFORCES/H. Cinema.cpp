#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,n,z,k,cnt,i;
    char s[1000010];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&k);
        z = 0;
        cnt = 0;
        scanf("%s",&s);
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                cnt++;
                if(cnt == (k+1))
                    z = 1;
            }
            else
                cnt=0;
        }

        if(z == 1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
