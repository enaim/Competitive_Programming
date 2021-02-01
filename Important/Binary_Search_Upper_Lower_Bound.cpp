#include<bits/stdc++.h>
using namespace std;


int main()
{
    int ar[]={1,2,3,4,4,4,4,4,5,6,7};
    int n = sizeof(ar)/sizeof(int);
    int l,r,mid,val;

    l = 0;
    r = n-1;
    val = 4;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(ar[mid]<val)
            l = mid+1;
        else
            r = mid-1;
    }
    printf("Lower bound - > %d\n",r+1);

    l = 0;
    r = n-1;
    val = 4;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(ar[mid]>val)
            r = mid-1;
        else
            l = mid+1;
    }
    printf("Upper bound - > %d\n",l-1);

    return 0;
}
