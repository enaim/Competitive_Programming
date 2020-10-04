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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int ar[200010];
int i,j,k,n,last,last1,last2;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    string str1="";
    string str2="";
    while(1==scanf("%d",&n))
    {

        str1="";
        str2="";
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        if(n==1)
        {
            printf("1\nL\n");
            continue;
        }
        i = 0;
        j = n-1;
        if(ar[i]==ar[j])
        {
            str1+='L';
            for(k=i+1;k<j;k++)
                if(ar[k]>ar[k-1])
                    str1+='L';
                else
                    break;
            str2+='R';
            for(k=j-1;k>i;k--)
                if(ar[k]>ar[k+1])
                    str2+='R';
                else
                    break;
            if(str1.size()<str2.size())
                cout<<str2.size()<<endl<<str2<<endl;
            else
                cout<<str1.size()<<endl<<str1<<endl;
            continue;
        }
        if(ar[i]>ar[j])
        {
            last = ar[j];
            str1+='R';
            str2+='R';
            j--;
        }
        else
        {
            last = ar[i];
            str1+='L';
            str2+='L';
            i++;
        }
        while(i<=j)
        {
            if(ar[i]>last && ar[i]<ar[j])
            {
                str1+='L';
                str2+='L';
                last = ar[i];
                i++;

            }
            else if(ar[j]>last && ar[i]>ar[j])
            {
                str1+='R';
                str2+='R';
                last = ar[j];
                j--;
            }
            else if(ar[i]>last)
            {
                str1+='L';
                str2+='L';
                last = ar[i];
                i++;
            }
            else if(ar[j]>last)
            {
                str1+='R';
                str2+='R';
                last = ar[j];
                j--;
            }
            else if(ar[i]==ar[j] && ar[i]>last)
            {
                last1 = last;
                last2 = last;
                for(k=i;k<j;k++)
                    if(ar[k]>last1)
                        str1+='L',last1 = ar[k];
                    else
                        break;
                for(k=j;k>i;k--)
                    if(ar[k]>last2)
                        str2+='R',last2 = ar[k];
                    else
                        break;
                break;
            }
            else
                break;
        }
        if(str1.size()<str2.size())
            cout<<str2.size()<<endl<<str2<<endl;
        else
            cout<<str1.size()<<endl<<str1<<endl;
    }

    return 0;
}
