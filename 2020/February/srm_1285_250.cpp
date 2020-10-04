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

class LimpingDog
{
public:
	int countSteps(int time)
	{
	    int cnt = 0,i;
	    if(time==0)
            return 0;
	    for(i=1;i<=10^7;i++)
        {
            if(i%4==1 || i%4==2 || i%4==0)
                cnt++;
            else if(cnt+2<=time)
                cnt+=2;
            else
            {
                i--;
                break;
            }

            if(i%47==0)
                cnt+=42;
            if(cnt>=time)
                break;
        }
        return i;
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

	LimpingDog objectLimpingDog;

	//test case0
	int param00 = 2;
	int ret0 = objectLimpingDog.countSteps(param00);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 3;
	int ret1 = objectLimpingDog.countSteps(param10);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 6;
	int ret2 = objectLimpingDog.countSteps(param20);
	int need2 = 5;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 80;
	int ret3 = objectLimpingDog.countSteps(param30);
	int need3 = 47;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 104;
	int ret4 = objectLimpingDog.countSteps(param40);
	int need4 = 50;
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 806000;
	int ret5 = objectLimpingDog.countSteps(param50);
	int need5 = 376000;
	assert_eq(5,ret5,need5);

	//test case6
	int param60 = 54321;
	int ret6 = objectLimpingDog.countSteps(param60);
	int need6 = 25346;
	assert_eq(6,ret6,need6);

}
