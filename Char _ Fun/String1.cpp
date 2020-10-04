#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char ch;
    char word[20][50],name[50];
    int l,i,stringLength,n,cnt;

    while(scanf("%d%s",&n,name)==2)
    {
        for(i=0;i<n;i++)
            scanf("%s",word[i]);

        cnt = 0;

        for(i=0;i<n;i++)
        {
            if(0==strcmp(word[i],name))      ///strcmp = string compare
                cnt++;
        }

        printf("Total Match: %d\n",cnt);

    }

    return 0;
}
