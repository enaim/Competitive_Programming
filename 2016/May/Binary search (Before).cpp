#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>

using namespace std;

int ar[100];
int x;

int Binary_Search_Before(int first,int last)
{
    int mid;

    if(x < ar[first])
        return -1;

    while(first<last)
    {
        mid = (first + last + 1) / 2;

        if(ar[mid] == x)
            return mid;
        else if(ar[mid] < x)
            first = mid ;
        else
            last  = mid - 1;
    }

    return first;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,ind;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        printf("Enter The Target Number: ");
        scanf("%d",&x);

//        sort(&ar[0],&ar[n]);
        ind = Binary_Search_Before(0,n-1);

        printf("Previous Index of Target: %d\n",ind);
    }

    return 0;
}
