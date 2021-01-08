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

ll nCr(ll n, ll r)
{
    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}


class ChristmasLightsFixing
{
public:
	vector <int> fixingTime(int N, long long step)
	{
	    ll sum = step,sz = -1, i, n = N, temp;
	    vector<int>vec;
        for(i=1;i<=n;i++)
        {
            temp = nCr(n,i);
            if(step>temp)
                step-=temp;
            else
            {
                sz = i;
                break;
            }
        }
        ll cnt = 1;
        for(i=1;i<=n && cnt<=sz;i++)
        {
            temp = nCr(n-i,sz-cnt);
            if(temp>=step)
            {
                int x = i-1;
                vec.push_back(x);
                cnt++;
            }
            else
                step-=temp;
        }
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

	ChristmasLightsFixing objectChristmasLightsFixing;

	//test case0
	int param00 = 5;
	long long param01 = 16;
	vector <int> ret0 = objectChristmasLightsFixing.fixingTime(param00,param01);
	vector <int> need0;
	need0.push_back(0);
	need0.push_back(1);
	need0.push_back(2);
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 40;
	long long param11 = 1099511627775;
	vector <int> ret1 = objectChristmasLightsFixing.fixingTime(param10,param11);
	vector <int> need1;
	need1.push_back(0);
	need1.push_back(1);
	need1.push_back(2);
	need1.push_back(3);
	need1.push_back(4);
	need1.push_back(5);
	need1.push_back(6);
	need1.push_back(7);
	need1.push_back(8);
	need1.push_back(9);
	need1.push_back(10);
	need1.push_back(11);
	need1.push_back(12);
	need1.push_back(13);
	need1.push_back(14);
	need1.push_back(15);
	need1.push_back(16);
	need1.push_back(17);
	need1.push_back(18);
	need1.push_back(19);
	need1.push_back(20);
	need1.push_back(21);
	need1.push_back(22);
	need1.push_back(23);
	need1.push_back(24);
	need1.push_back(25);
	need1.push_back(26);
	need1.push_back(27);
	need1.push_back(28);
	need1.push_back(29);
	need1.push_back(30);
	need1.push_back(31);
	need1.push_back(32);
	need1.push_back(33);
	need1.push_back(34);
	need1.push_back(35);
	need1.push_back(36);
	need1.push_back(37);
	need1.push_back(38);
	need1.push_back(39);
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 50;
	long long param21 = 7;
	vector <int> ret2 = objectChristmasLightsFixing.fixingTime(param20,param21);
	vector <int> need2;
	need2.push_back(6);
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 7;
	long long param31 = 47;
	vector <int> ret3 = objectChristmasLightsFixing.fixingTime(param30,param31);
	vector <int> need3;
	need3.push_back(1);
	need3.push_back(2);
	need3.push_back(6);
	assert_eq(3,ret3,need3);

}
