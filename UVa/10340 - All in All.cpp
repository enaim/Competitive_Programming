#include <stdio.h>
#include <string.h>
#include <math.h>

const int SZ =  2000000;

char s[SZ];
char t[SZ];


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,cnt,lens,lent;

    while(2==scanf("%s%s",s,t))
    {
        lens = strlen(s);
        lent = strlen(t);
        cnt=0;
        i=0;
        for(j=0;j<lent;j++)
        {
            if(s[i]==t[j])
            {
                i++;
                cnt++;
                continue;
            }
        }
        if(cnt==lens)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

