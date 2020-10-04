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

typedef long long ll;


ll loc[2000010];
int flag[2000010];

class MemoryGame
{
public:
	long long countSteps(int n, int seed)
	{
        int i,j;
        ll cnt = 0LL;
	    for(i=0;i<2000000;i++)
            flag[i]=0;
	    for(i=0;i<2*n;i++)
            loc[i] = i/2;

        ll state = seed;
        for(i=2*n - 1;i>=1;i--)
        {
            j = state % (i+1);
            swap(loc[i],loc[j]);
            state = (((state%(1LL<<31LL)) * 1103515245LL) + 12345LL)%(1LL<<31LL);
        }

        i=-1;
        while(i<2*n-1)
        {
            i++;
            flag[loc[i]]++;
            if(flag[loc[i]]==2)
            {
                cnt++;
                continue;
            }
            i++;
            flag[loc[i]]++;
            if(flag[loc[i]]==2)
            {
                if(loc[i]==loc[i-1])
                    cnt++;
                else
                    cnt+=2;
                continue;
            }
            cnt++;
        }
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

	MemoryGame objectMemoryGame;

	//test case0
	int param00 = 1;
	int param01 = 47;
	long long ret0 = objectMemoryGame.countSteps(param00,param01);
	long long need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 2;
	int param11 = 47474747;
	long long ret1 = objectMemoryGame.countSteps(param10,param11);
	long long need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 2;
	int param21 = 42;
	long long ret2 = objectMemoryGame.countSteps(param20,param21);
	long long need2 = 3;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 7;
	int param31 = 123456;
	long long ret3 = objectMemoryGame.countSteps(param30,param31);
	long long need3 = 12;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 100;
	int param41 = 100;
	long long ret4 = objectMemoryGame.countSteps(param40,param41);
	long long need4 = 166;
	assert_eq(4,ret4,need4);

}
