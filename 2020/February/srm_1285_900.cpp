#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

string str;
int temp1,temp2,sz;
long long dp[3010][3010];
long long mod = 1000000007;

long long go(int last,int pos)
{
    if(pos==sz)
       return 1LL;

    long long &re = dp[last][pos];
    if(re !=-1LL)
        return re;
    re = 0;
    int w=0,b=0;
    for(int i=pos;i<sz;i++)
    {
        if(str[i]=='w')
            w++;
        else
            b++;
        if(w==temp1 && b==temp2)
        {
            re += (2LL*go(pos,i+1));
            re%=mod;
        }
        else if(w==temp1)
        {
            re += go(pos,i+1);
            re%=mod;
        }
        else if(b==temp2)
        {
            re += go(pos,i+1);
            re%=mod;
        }
    }
    return re;
}

class BlackAndWhiteBallsEasy
{
public:
	int getNumber(vector <int> balls, int white, int black)
	{
	    temp1 = white;
	    temp2 = black;
	    str.clear();
	    str = "#";
	    int i,j;
	    for(i=0;i<balls.size();i++)
        {
            if(i%2==0)
            {
                for(j=0;j<balls[i];j++)
                    str+="w";
            }
            else
            {
                for(j=0;j<balls[i];j++)
                    str+="b";
            }
        }
        sz = str.size();
        memset(dp,-1,sizeof dp);
        return go(0,1);
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	BlackAndWhiteBallsEasy objectBlackAndWhiteBallsEasy;

	//test case0
	vector <int> param00;
	param00.push_back(2);
	param00.push_back(2);
	int param01 = 1;
	int param02 = 2;
	int ret0 = objectBlackAndWhiteBallsEasy.getNumber(param00,param01,param02);
	int need0 = 4;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(2);
	param10.push_back(1);
	param10.push_back(3);
	int param11 = 1;
	int param12 = 1;
	int ret1 = objectBlackAndWhiteBallsEasy.getNumber(param10,param11,param12);
	int need1 = 14;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(1);
	param20.push_back(1);
	param20.push_back(1);
	param20.push_back(1);
	param20.push_back(1);
	int param21 = 1;
	int param22 = 1;
	int ret2 = objectBlackAndWhiteBallsEasy.getNumber(param20,param21,param22);
	int need2 = 28;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(2);
	param30.push_back(2);
	param30.push_back(2);
	param30.push_back(2);
	param30.push_back(2);
	int param31 = 1;
	int param32 = 1;
	int ret3 = objectBlackAndWhiteBallsEasy.getNumber(param30,param31,param32);
	int need3 = 236;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(3);
	param40.push_back(6);
	param40.push_back(3);
	param40.push_back(10);
	int param41 = 2;
	int param42 = 3;
	int ret4 = objectBlackAndWhiteBallsEasy.getNumber(param40,param41,param42);
	int need4 = 12;
	assert_eq(4,ret4,need4);

	//test case5
	vector <int> param50;
	param50.push_back(30);
	param50.push_back(15);
	param50.push_back(45);
	param50.push_back(20);
	param50.push_back(8);
	param50.push_back(13);
	param50.push_back(7);
	param50.push_back(3);
	param50.push_back(25);
	param50.push_back(10);
	int param51 = 3;
	int param52 = 2;
	int ret5 = objectBlackAndWhiteBallsEasy.getNumber(param50,param51,param52);
	int need5 = 180210099;
	assert_eq(5,ret5,need5);

}
