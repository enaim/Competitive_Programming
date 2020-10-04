#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>

using namespace std;

int ar[100],x;

int Binary_Search(int mn,int avg,int mx)
{
    if(ar[mn] == x)
        return mn;
    else if(ar[mx] == x)
        return  mx;
    else if(ar[avg] == x)
        return  avg;
    else if(ar[avg] < x)
        Binary_Search(avg+1,(avg+mx)/2,mx);
    else
        Binary_Search(mn,(avg+mn)/2,avg);
}



int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,ind;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        printf("Enter The target Number: ");
        scanf("%d",&x);

        sort(&ar[0],&ar[n]);
        ind = Binary_Search(0,n/2,n);

        printf("Target Index : %d\n",ind);
    }

    return 0;
}

