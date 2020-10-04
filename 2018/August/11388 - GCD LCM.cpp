#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main()
{
    int tks,ks=1,x,a,b,temp,ans,y,z;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&a,&b);
        if(b%a==0)
        {
            printf("%d %d\n",a,b);
        }
        else
            printf("-1\n");
    }


    return 0;
}
