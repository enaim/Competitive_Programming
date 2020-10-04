#include <stdio.h>

long long ar[10000010];

int main() {
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        long long sum = 0LL,s;
        int n;
        scanf("%d%lld",&n,&s);
        int i,j,flag=0;
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        i = 0;
        j = -1;
        while(j<n-1)
        {
            j++;
            sum+=ar[j];
            if(sum==s)
            {
                flag = 1;
                break;
            }
            while(sum>s && i<=j)
            {
                sum-=ar[i];
                i++;
                if(sum==s)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag==1)
            printf("%d %d\n",i+1,j+1);
        else
            printf("-1\n");
    }

	return 0;
}
