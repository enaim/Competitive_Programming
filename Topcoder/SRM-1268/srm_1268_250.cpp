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

class Alpha
{
public:
	int maxPref(string s)
	{
	    int cnt = 0,x = 0;
	    for(int i=0;i<s.size();i++)
            if(s[i]-'a'==x)
            {
                cnt++;
                x++;
            }
            else
                break;
        return cnt;
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

	Alpha objectAlpha;

	//test case0
	string param00 = "abctyf";
	int ret0 = objectAlpha.maxPref(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "abcdefghijklmnopqrstuvwxyz";
	int ret1 = objectAlpha.maxPref(param10);
	int need1 = 26;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "zyx";
	int ret2 = objectAlpha.maxPref(param20);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "abcdegfhijk";
	int ret3 = objectAlpha.maxPref(param30);
	int need3 = 5;
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "ba";
	int ret4 = objectAlpha.maxPref(param40);
	int need4 = 0;
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "aabc";
	int ret5 = objectAlpha.maxPref(param50);
	int need5 = 1;
	assert_eq(5,ret5,need5);

	//test case6
	string param60 = "abcdefghijklmno";
	int ret6 = objectAlpha.maxPref(param60);
	int need6 = 15;
	assert_eq(6,ret6,need6);

}
