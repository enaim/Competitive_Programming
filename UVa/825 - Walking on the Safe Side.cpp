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

int dp[1000][1000];
bool flag[1000][1000];
int m,n;
int invalid;

int convert_to_integer(char str[])
{
	int x = 0,i,len;
	len = strlen(str);

	for(i=0;i<len;i++)
	{
		x = x*10 + (str[i]-'0');
	}

	return x;
}

int go(int a,int b)
{
	if(!flag[a][b])
		return 0;
	if(a == m && b == n)
		return 1;
	if(a > m || b > n)
		return 0;

	int &re = dp[a][b];
	if(re != invalid)	
		return re;
	re = 0;
	re = go(a+1,b) + go(a,b+1);

	return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	memset(&invalid,0x1f,sizeof invalid);
	
	char str[100],temp[100],str1[10];
    int tks,ks=1,i,j,k,t,res,x,len;
    scanf("%d",&tks);
    while(tks--)
    {
    	memset(flag,1,sizeof flag);
		memset(dp,0x1f,sizeof dp);

    	scanf("%d%d",&m,&n);
    	gets(str1);
    	for(int i=1;i<=m;i++)
    	{
    		gets(str);
    		len = strlen(str);
    		k = 0;
    		t = 0;
    		for(j=0;j<=len;j++)
    		{
    			if(str[j] == ' ' || j == len)
    			{
    				temp[k] = '\0';
    				x = convert_to_integer(temp);
    				k = 0;
    				if(t==0)
    					t++;
    				else
    					flag[i][x] = false;
    			}
    			else
    				temp[k++] = str[j];
    		}
    	}
    	res = go(1,1);
    	if(ks==1)	
        	printf("%d\n",res);
        else
        	printf("\n%d\n",res);
        ks++;
    }

    return 0;
}
