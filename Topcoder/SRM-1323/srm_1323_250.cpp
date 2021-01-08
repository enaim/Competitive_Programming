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

class ChristmasCrackerHappiness
{
public:
	int solve(int N, vector <int> winner, vector <int> loser)
	{
	    set<int>st;
	    int n = winner.size();
	    for(int i=0;i<n;i++)
            st.insert(winner[i]);
        return max(0,(N-1)-((int)st.size()));
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

	ChristmasCrackerHappiness objectChristmasCrackerHappiness;

	//test case0
	int param00 = 2;
	vector <int> param01;
	vector <int> param02;
	int ret0 = objectChristmasCrackerHappiness.solve(param00,param01,param02);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 5;
	vector <int> param11;
	param11.push_back(0);
	param11.push_back(1);
	param11.push_back(0);
	param11.push_back(3);
	param11.push_back(2);
	param11.push_back(0);
	param11.push_back(4);
	param11.push_back(0);
	vector <int> param12;
	param12.push_back(3);
	param12.push_back(3);
	param12.push_back(4);
	param12.push_back(1);
	param12.push_back(0);
	param12.push_back(2);
	param12.push_back(1);
	param12.push_back(3);
	int ret1 = objectChristmasCrackerHappiness.solve(param10,param11,param12);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 12;
	vector <int> param21;
	param21.push_back(3);
	param21.push_back(1);
	param21.push_back(4);
	param21.push_back(1);
	param21.push_back(5);
	param21.push_back(9);
	param21.push_back(2);
	param21.push_back(6);
	vector <int> param22;
	param22.push_back(5);
	param22.push_back(3);
	param22.push_back(5);
	param22.push_back(8);
	param22.push_back(9);
	param22.push_back(7);
	param22.push_back(9);
	param22.push_back(3);
	int ret2 = objectChristmasCrackerHappiness.solve(param20,param21,param22);
	int need2 = 4;
	assert_eq(2,ret2,need2);

}


