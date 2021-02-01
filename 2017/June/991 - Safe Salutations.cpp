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

int dp[11];
int invalid;

int go(int n)
{
	if(n<=1)
		return 1;
	int &re = dp[n];
	if(re != invalid)
		return re;

	re = 0;
	for(int i=1;i<=n;i++)
		re+= (go(i-1)*go(n-i));

	return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	int res,n,t = 1;
	memset(&invalid,0x1f,sizeof invalid);

	while(scanf("%d",&n) == 1)
	{
		memset(dp,0x1f,sizeof dp);

		res	= go(n);
		if(t==1)
			printf("%d\n",res);
		else
			printf("\n%d\n",res);
		t++;
	}

    return 0;
}
