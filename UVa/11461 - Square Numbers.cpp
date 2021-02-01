#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int a,b,cnt;
    while(scanf("%d%d",&a,&b) == 2 && (a || b))
    {
        cnt = 0;
        for(int i = sqrt(a);i<=sqrt(b);i++)
        {
            if(a <= i*i && i*i <=b)
                cnt++;
            else if(i*i > b)
                break;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
