#include<bits/stdc++.h>
using namespace std;

int countSteps(int time)
{
  int cnt = 0,i;
  if(time==0)
        return 0;
  for(i=1;i<=10^7;i++)
    {
        if(i%4==1 || i%4==2 || i%4==0)
            cnt++;
        else if(cnt+2<=time)
            cnt+=2;
        else
        {
            i--;
            break;
        }

        if(i%47==0)
            cnt+=42;
        if(cnt>=time)
            break;
    }
    return i;
}

int main()
{
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",ks++,countSteps(n));
    }

    return 0;
}
