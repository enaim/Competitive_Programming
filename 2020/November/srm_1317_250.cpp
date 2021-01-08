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

class JumpAcrossTheRiver
{
public:
	long long minLength(int N, int M, int J)
	{
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

	JumpAcrossTheRiver objectJumpAcrossTheRiver;

	//test case0
	int param00 = 10;
	int param01 = 1;
	int param02 = 1;
	long long ret0 = objectJumpAcrossTheRiver.minLength(param00,param01,param02);
	long long need0 = 10;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	int param11 = 1;
	int param12 = 3;
	long long ret1 = objectJumpAcrossTheRiver.minLength(param10,param11,param12);
	long long need1 = 4;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 10;
	int param21 = 1234567;
	int param22 = 10;
	long long ret2 = objectJumpAcrossTheRiver.minLength(param20,param21,param22);
	long long need2 = 82;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 10;
	int param31 = 1234567;
	int param32 = 4;
	long long ret3 = objectJumpAcrossTheRiver.minLength(param30,param31,param32);
	long long need3 = 87;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 123456;
	int param41 = 1000000007;
	int param42 = 2;
	long long ret4 = objectJumpAcrossTheRiver.minLength(param40,param41,param42);
	long long need4 = 27561114912135;
	assert_eq(4,ret4,need4);

}
