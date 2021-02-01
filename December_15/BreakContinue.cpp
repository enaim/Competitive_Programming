#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    while(1==scanf("%d",&n))
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(i>20)    break; ///Jump out of the loop
            if(i%3==0)  continue; ///Jump to the change portion of loop without execution remaining portion of the loop

            sum+=i;
            printf("i->%d\n",i);
        }
        printf("\n\n\t\tSUM: %d\n",sum);
    }

    return 0;
}
