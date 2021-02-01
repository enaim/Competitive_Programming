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

typedef long long ll;

bool func(ll n)
{
    ll ar[100];
    ll i,x,y;
    if(n<=9)
        return true;
    i = 1;
    while(n!=0)
    {
        y = n%10;
        n = n/10;
        ar[i]=y;
        i++;
    }
    ll k = 0,j;
    for(j=i-1;j>1;j--)
    {
        k++;
        if(k%2==1 && ar[j]<ar[j-1])
            continue;
        else if(k%2==0 && ar[j]>ar[j-1])
            continue;
        else
            return false;
    }

    return true;
}

class MagicNumbersAgain
{
public:
	ll count(long long A, long long B)
	{
	    ll cnt = 0,i;
	    for(i=1;i<=100010;i++)
        {
            if(i*i>=A && i*i<=B)
            {
                int x = func(i*i);
                if(x)
                    cnt++;
            }
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

	MagicNumbersAgain objectMagicNumbersAgain;

	//test case0
	long long param00 = 1;
	long long param01 = 64;
	int ret0 = objectMagicNumbersAgain.count(param00,param01);
	int need0 = 7;
	assert_eq(0,ret0,need0);

	//test case1
	long long param10 = 50;
	long long param11 = 60;
	int ret1 = objectMagicNumbersAgain.count(param10,param11);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	long long param20 = 121;
	long long param21 = 121;
	int ret2 = objectMagicNumbersAgain.count(param20,param21);
	int need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	long long param30 = 5679;
	long long param31 = 1758030;
	int ret3 = objectMagicNumbersAgain.count(param30,param31);
	int need3 = 73;
	assert_eq(3,ret3,need3);

	//test case4
	long long param40 = 1304164;
	long long param41 = 2000000;
	int ret4 = objectMagicNumbersAgain.count(param40,param41);
	int need4 = 14;
	assert_eq(4,ret4,need4);

}

