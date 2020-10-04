#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>

using namespace std;

int ar[100],x;

int Binary_Search(int first,int last)
{
    int mid;

    while(first<=last)
    {
        mid = (first + last) / 2;

        if(ar[mid] == x)
            return mid;
        else if(ar[mid] < x)
            first = mid + 1;
        else
            last  = mid - 1;
    }

    return -1;
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

        printf("Enter The Target Number: ");
        scanf("%d",&x);

//        sort(&ar[0],&ar[n]);
        ind = Binary_Search(0,n-1);

        printf("Target Index : %d\n",ind);
    }

    return 0;
}

