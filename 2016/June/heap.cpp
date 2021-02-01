#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


void heapify(int ar[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && ar[l] > ar[largest])
        largest = l;

    if (r < n && ar[r] > ar[largest])
        largest = r;

    if (largest != i)
    {

        temp = ar[i];
        ar[i] = ar[largest];
        ar[largest] = temp;

        heapify(ar, n, largest);
    }
}


void HeapSort(int ar[], int n)
{
    int temp;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);

    for (int i=n-1; i>=0; i--)
    {
        temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp ;

        heapify(ar, i, 0);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i;
    int ar[100];

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        HeapSort(ar,n);

        cout << "Sorted array is \n";

        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
    }

    return 0;
}
