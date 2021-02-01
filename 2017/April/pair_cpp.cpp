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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,pis> pipis;


bool compare(pii a,pii b)
{
    return a.second<b.second;
}

vector<pii>v;

int main()
{
    pii a;
    a = make_pair(1,3);
    v.push_back(a);
    v.push_back(make_pair(1,-3));
    v.push_back(make_pair(2,3));
    v.push_back(make_pair(-5,4));

    for(int i=0;i<v.size();i++)
    {
        printf("%d - > %d\n",v[i].first,v[i].second);
    }

    puts("sort based on first index \n");

    sort(v.begin(),v.end());
    for(vector<pii> :: iterator it = v.begin() ; it != v.end() ; it++)
    {
        cout << it->first << " " << it->second << endl;
    }

     for(int i=0;i<v.size();i++)
    {
        printf("%d - > %d\n",v[i].first,v[i].second);
    }

    puts("sort based on second index \n");

    sort(v.begin(),v.end(),compare);
    for(vector<pii> :: iterator it = v.begin() ; it != v.end() ; it++)
    {
        pii p = *it;
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}

