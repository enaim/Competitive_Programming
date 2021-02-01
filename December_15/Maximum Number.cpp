#include<stdio.h>
#include<math.h>


int main()
{
    int n,maximum,val,i;
    while(1==scanf("%d",&n))
    {
        maximum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            if(maximum<val)
                maximum = val;
        }

        printf("Maximum Value: %d\n",maximum);
    }

    return 0;
}

