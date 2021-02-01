#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

int ar[]={-2,-2,2,2,-1,-1,1,1};
int ac[]={-1,1,-1,1,-2,2,-2,2};

int main()
{
    int tks,ks=1,x,i,n,cnt,y;
    char s[5];

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",s);
        x  = s[0] - 'a'+1;
        y  = s[1]-'0';
        cnt= 0;
        for(i=0;i<8;i++)
        {
            if((y+ac[i])>0 && (y+ac[i])<9 && (x+ar[i])>0 && (x+ar[i])<9)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }


    return 0;
}
