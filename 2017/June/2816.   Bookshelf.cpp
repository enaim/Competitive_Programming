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

const int Size = 110;
int dp[Size][Size];
int ar[Size];
int invalid;
int n;


int BookSelf(int i,int k)
{

	if(k == 0 && i == n)
		return 0;
	if(k == 0) 
		return OO;

	int &re = dp[i][k];
	if(re != invalid)
		return re;

	re = OO;
	int mx = ar[i];
	for(int j=i;j<n-k+1;j++)
	{
		if(mx < ar[j])
			mx = ar[j];
		re = min(re,mx + BookSelf(j+1,k-1));
	} 

	return re;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

	int k,i,res;
	memset(&invalid,0x1f,sizeof invalid);

	while(scanf("%d%d",&n,&k) == 2 && n && k)
	{
		memset(dp,0x1f,sizeof dp);
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);

		res	= BookSelf(0,k);
		printf("%d\n",res);
	}

    return 0;
}
