#include<string.h>
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

#define OO (1<<25)

const int SIZE = 110;
int dp[SIZE][SIZE][SIZE];

int _totalArea(int A, int B, int C, int S)
	{
	    int ar[3],i;
        ar[0] = A;  ar[1]=B;    ar[2]=C;
        sort(&ar[0],&ar[3]);

        if(ar[0] < S)   return 0;
        if(ar[0] == S)  return ar[1]*ar[2];

	    int &re = dp[ar[0]][ar[1]][ar[2]];
	    if(re >  -1)   return re;
	    re = -OO;

	    for(i=1;i<ar[0];i++)
            re = max(re,_totalArea(ar[0]-i,ar[1],ar[2],S)+_totalArea(i,ar[1],ar[2],S));
        for(i=1;i<ar[1];i++)
            re = max(re,_totalArea(ar[0],ar[1]-i,ar[2],S)+_totalArea(ar[0],i,ar[2],S));
        for(i=1;i<ar[2];i++)
            re = max(re,_totalArea(ar[0],ar[1],ar[2]-i,S)+_totalArea(ar[0],ar[1],i,S));

        return re = max(re,ar[1]*ar[2]);
	}


class CheeseSlicing
{
public:
	int totalArea(int A, int B, int C, int S)
	{
	    memset(dp,-1,sizeof dp);
        return _totalArea(A,B,C,S);
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


	CheeseSlicing objectCheeseSlicing;

	//test case0
	int param00 = 1;
	int param01 = 3;
	int param02 = 3;
	int param03 = 2;
	int ret0 = objectCheeseSlicing.totalArea(param00,param01,param02,param03);
	int need0 = 0;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 5;
	int param11 = 3;
	int param12 = 5;
	int param13 = 3;
	int ret1 = objectCheeseSlicing.totalArea(param10,param11,param12,param13);
	int need1 = 25;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 5;
	int param21 = 5;
	int param22 = 5;
	int param23 = 2;
	int ret2 = objectCheeseSlicing.totalArea(param20,param21,param22,param23);
	int need2 = 58;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 49;
	int param31 = 92;
	int param32 = 20;
	int param33 = 3;
	int ret3 = objectCheeseSlicing.totalArea(param30,param31,param32,param33);
	int need3 = 30045;
	assert_eq(3,ret3,need3);

}
