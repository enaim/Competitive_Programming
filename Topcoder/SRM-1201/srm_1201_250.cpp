#include <bits/stdc++.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class BinaryCalculator
{
public:
	int minimumSteps(int a, int b)
	{
	    int dp[210];
	    dp[0]=0;
	    dp[1]=2;
	    dp[2]=4;
	    dp[3]=1;
	    for(int i=4;i<=100;i++)
        {
            dp[i] = dp[i-3]+dp[3];
            i++;
            dp[i] = dp[i-3]+dp[3];
            i++;
            dp[i] = dp[i-3]+dp[3];
        }
	    dp[101]=3;
	    dp[102]=1;
	    dp[103]=4;
	    for(int i=104;i<=200;i++)
        {
            dp[i] = dp[i-2]+dp[102];
            i++;
            dp[i] = dp[i-2]+dp[102];
        }
        if(b-a>=0)
            return dp[b-a];
        else
            return dp[a-b+100];
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

	BinaryCalculator objectBinaryCalculator;

	//test case0
	int param00 = 10;
	int param01 = 14;
	int ret0 = objectBinaryCalculator.minimumSteps(param00,param01);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 23;
	int param11 = 23;
	int ret1 = objectBinaryCalculator.minimumSteps(param10,param11);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 18;
	int param21 = 12;
	int ret2 = objectBinaryCalculator.minimumSteps(param20,param21);
	int need2 = 3;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 23;
	int param31 = 62;
	int ret3 = objectBinaryCalculator.minimumSteps(param30,param31);
	int need3 = 13;
	assert_eq(3,ret3,need3);

}
