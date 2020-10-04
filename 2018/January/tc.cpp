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

class MakeTwoConsecutive
{
public:
	string solve(string S)
	{
	    string imp = "Impossible";
	    string pos ="Possible";
	    if(S.size()<3)  return imp;
	    for(int i=1;i<S.size();i++)
            if(S[i-1]==S[i])
                return pos;

        for(int i=2;i<S.size();i++)
            if(S[i-2]==S[i])
                return pos;

	    return imp;
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

	MakeTwoConsecutive objectMakeTwoConsecutive;

	//test case0
	string param00 = "VIKING";
	string ret0 = objectMakeTwoConsecutive.solve(param00);
	string need0 = "Possible";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "BCAB";
	string ret1 = objectMakeTwoConsecutive.solve(param10);
	string need1 = "Impossible";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "XX";
	string ret2 = objectMakeTwoConsecutive.solve(param20);
	string need2 = "Impossible";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "A";
	string ret3 = objectMakeTwoConsecutive.solve(param30);
	string need3 = "Impossible";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "AABB";
	string ret4 = objectMakeTwoConsecutive.solve(param40);
	string need4 = "Possible";
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "QWERTYY";
	string ret5 = objectMakeTwoConsecutive.solve(param50);
	string need5 = "Possible";
	assert_eq(5,ret5,need5);

	//test case6
	string param60 = "ITHINKYOUAREAHUMAN";
	string ret6 = objectMakeTwoConsecutive.solve(param60);
	string need6 = "Impossible";
	assert_eq(6,ret6,need6);

	//test case7
	string param70 = "BOB";
	string ret7 = objectMakeTwoConsecutive.solve(param70);
	string need7 = "Possible";
	assert_eq(7,ret7,need7);

}
