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

class LogiciansAndBeer
{
public:
	int bringBeer(string str)
	{
	    int n = str.size();
	    int flag = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, i, start = -1;

	    if(str[n-1]=='?')
            return -1;
        for(i=0;i<n;i++)
        {
            if(str[i]=='+')
                cnt1++;
            else if(str[i]=='?')
                cnt2++;
        }
        if(cnt2+cnt1==n)
        {
            if(cnt1==1 && str[n-1]=='+')
                return n;
            else
                return -1;
        }

	    for(i=0;i<n;i++)
        {
            if(str[i]=='-' && flag == 0)
                start = i,cnt3++,flag=1;
            else if(str[i]=='-' && flag == 1)
                cnt3++;
        }
        if(n-start==cnt3 && cnt1==0)
            return cnt2;
        return -1;
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

	LogiciansAndBeer objectLogiciansAndBeer;

	//test case0
	string param00 = "??+";
	int ret0 = objectLogiciansAndBeer.bringBeer(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "?????-";
	int ret1 = objectLogiciansAndBeer.bringBeer(param10);
	int need1 = 5;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "-+-+-+";
	int ret2 = objectLogiciansAndBeer.bringBeer(param20);
	int need2 = -1;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "------";
	int ret3 = objectLogiciansAndBeer.bringBeer(param30);
	int need3 = 1;
	assert_eq(3,ret3,need3);

}
