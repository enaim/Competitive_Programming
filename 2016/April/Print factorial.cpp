#include<stdio.h>
#include<math.h>
#include<string.h>

int n;
int Q[100];

void fact(int depth)
{
    int x;

    if(depth == n)
    {
        for(int i=0;i<n;i++)
            printf("%d ",Q[i]);
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<depth;j++)
        {
            x = true;
            if(Q[j]==i)
            {
                x = false;
                break;
            }
        }
        if(x == false)
            continue;

        Q[depth] = i;
        fact(depth+1);
    }
}



int main()
{

    while(1==scanf("%d",&n))
    {
        fact(0);
    }

    return 0;
}
