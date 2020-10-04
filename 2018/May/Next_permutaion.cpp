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
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;


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

        sort(&ar[0],&ar[n]);
        do{
            for(i=0;i<n;i++)
                printf("%d ",ar[i]);
            printf("\n");
        }while(next_permutation(ar,ar+n));

//        string str;
//        cin>>str;
//        sort(str.begin(),str.end());
//        do{
//            printf("%s\n",str.c_str());
//        }while(next_permutation(str.begin(),str.end()));
    }

    return 0;
}
