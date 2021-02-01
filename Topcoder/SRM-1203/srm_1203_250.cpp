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

class A0Paper
{
public:
	string canBuild(vector <int> vec)
	{
	    int n = vec.size();

        for(int i=n-2;i>=0;i--)
            vec[i] += vec[i+1]/2;

        if(vec[0]>=1)
            return "Possible";
        else
            return "Impossible";
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

	A0Paper objectA0Paper;

	//test case0
	vector <int> param00;
	param00.push_back(0);
	param00.push_back(3);
	string ret0 = objectA0Paper.canBuild(param00);
	string need0 = "Possible";
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(0);
	param10.push_back(1);
	param10.push_back(2);
	string ret1 = objectA0Paper.canBuild(param10);
	string need1 = "Possible";
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(0);
	param20.push_back(0);
	param20.push_back(0);
	param20.push_back(0);
	param20.push_back(15);
	string ret2 = objectA0Paper.canBuild(param20);
	string need2 = "Impossible";
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(2);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(3);
	param30.push_back(2);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(5);
	param30.push_back(0);
	param30.push_back(3);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(1);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(5);
	string ret3 = objectA0Paper.canBuild(param30);
	string need3 = "Possible";
	assert_eq(3,ret3,need3);

}
