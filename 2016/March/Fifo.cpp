#include <stdio.h>
#include <string.h>
#include <math.h>


int ar[100],Front,Rare;


void push(int v)
{
    ar[Rare] = v;
    Rare++;

}
void pop()
{
    Front = Front+1 ;
}

int getFrontElement()
{
    return ar[Front];
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,v;
    Front = 0;
    Rare = 0;
    while(1==scanf("%d",&n))
    {
        if(n==1)
        {
            scanf("%d",&v);
            push(v);
        }
        else if(n==2)
            pop();
        else if(n==3)
        {
            v = getFrontElement();
            printf("v : %d\n",v);
        }
    }

    return 0;
}
