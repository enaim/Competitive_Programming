#include <stdio.h>

#include <algorithm>
using namespace std;

int a[1000];


bool comp(int first,int second)
{
    return first>second;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;

    while(2==scanf("%d%d",&n,&m))
    {

        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);


//        sort(&a[m],&a[n]);
        sort(&a[m],&a[n],comp);

        for(int i=0;i<n;i++)
            printf("%d -> %d\n",i,a[i]);

        printf("\n");
    }

    return 0;
}


