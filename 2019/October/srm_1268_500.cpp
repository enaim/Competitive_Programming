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

class BinaryDistance
{
public:
	int maxDist(int n, int v)
	{
	    int lev,temp,left,right,l,r,ans,lv;
	    left = right = lev = lv = l = r = 0;
	    temp = n;
	    while(temp!=1)
        {
            if(temp==2)
                left = 1;
            if(temp==3)
                right = 1;
            lev++;
            temp/=2;
        }
        if(v==1)
            return lev;
        temp = v;
        while(temp!=1)
        {
            if(temp==2)
                l = 1;
            if(temp==3)
                r = 1;
            lv++;
            temp/=2;
        }
        if(l==1)
        {
            if(right==1)
                ans = max(lev-lv,lv+lev);
            else
                ans = max(lev-lv,lv+lev-1);
        }
        else
        {
            if(right==1)
                ans = max(lev-lv,lv+lev);
            else
                ans = max(lev-1-lv,lv+lev);
        }
        return ans;
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

	BinaryDistance objectBinaryDistance;

	//test case0
	int param00 = 6;
	int param01 = 2;
	int ret0 = objectBinaryDistance.maxDist(param00,param01);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 6;
	int param11 = 6;
	int ret1 = objectBinaryDistance.maxDist(param10,param11);
	int need1 = 4;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 5;
	int param21 = 4;
	int ret2 = objectBinaryDistance.maxDist(param20,param21);
	int need2 = 3;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 2;
	int param31 = 2;
	int ret3 = objectBinaryDistance.maxDist(param30,param31);
	int need3 = 1;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 1000000000;
	int param41 = 1;
	int ret4 = objectBinaryDistance.maxDist(param40,param41);
	int need4 = 29;
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 20;
	int param51 = 7;
	int ret5 = objectBinaryDistance.maxDist(param50,param51);
	int need5 = 6;
	assert_eq(5,ret5,need5);

	//test case6
	int param60 = 12;
	int param61 = 4;
	int ret6 = objectBinaryDistance.maxDist(param60,param61);
	int need6 = 5;
	assert_eq(6,ret6,need6);

}
