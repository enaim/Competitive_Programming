#include<stdio.h>
#include<string.h>


int main()
{
//    freopen("in.txt","r",stdin);
    int tks,i,len,cnt1,cnt2,ks=1,x;
    char str[50][2],ch;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);

        for(i=0;i<9;i++)
            scanf("%s",str[i]);

        cnt1 = cnt2 = x = 0;
        for(i=0;i<10;i++)
        {
            if(i==3 || i==6 || i==9)
            {
                if(cnt1==3 || cnt2 == 3)
                    printf("Triple\n");
                else if(x==1)
                    printf("Pair\n");
                else
                    printf("Normal\n");
                cnt1 = cnt2 = x = 0;
            }

            if(str[i][0] =='b')
            {
                cnt1++;
                cnt2 = 0;
                if(cnt1 == 2)
                    x = 1;
            }
            if(str[i][0] =='g')
            {
                cnt2++;
                cnt1 = 0;
                if(cnt2 == 2)
                    x = 1;
            }
        }
    }

    return 0;
}
