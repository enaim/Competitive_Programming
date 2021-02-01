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

class ThreePartSplit
{
public:
	vector <int> split(int a, int d)
	{
	    int n = d-a;
	    vector<int>vec;
	    vec.push_back(a+ n/3);
	    vec.push_back(a + n/3 + n/3);
	    return vec;
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

	ThreePartSplit objectThreePartSplit;

	//test case0
	int param00 = 0;
	int param01 = 6;
	vector <int> ret0 = objectThreePartSplit.split(param00,param01);
	vector <int> need0;
	need0.push_back(2);
	need0.push_back(4);
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	int param11 = 14;
	vector <int> ret1 = objectThreePartSplit.split(param10,param11);
	vector <int> need1;
	need1.push_back(11);
	need1.push_back(12);
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 127;
	int param21 = 345;
	vector <int> ret2 = objectThreePartSplit.split(param20,param21);
	vector <int> need2;
	need2.push_back(199);
	need2.push_back(271);
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 0;
	int param31 = 100000000;
	vector <int> ret3 = objectThreePartSplit.split(param30,param31);
	vector <int> need3;
	need3.push_back(33333333);
	need3.push_back(66666666);
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 100;
	int param41 = 105;
	vector <int> ret4 = objectThreePartSplit.split(param40,param41);
	vector <int> need4;
	need4.push_back(101);
	need4.push_back(104);
	assert_eq(4,ret4,need4);

}
