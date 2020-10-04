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

class BirthdayCandy
{
public:
	int mostCandy(int k, vector <int> vec)
	{
	    int ans = 0,sz,i,sum;
	    sz = vec.size();
	    int n = k+1;
	    for(i=0;i<sz;i++)
        {
            if(vec[i]%n==0)
                sum = vec[i]/n;
            else
                sum = vec[i]/n + (vec[i]%n);
            ans = max(ans,sum);
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

	BirthdayCandy objectBirthdayCandy;

	//test case0
	int param00 = 9;
	vector <int> param01;
	param01.push_back(23);
	param01.push_back(7);
	int ret0 = objectBirthdayCandy.mostCandy(param00,param01);
	int need0 = 7;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 1;
	vector <int> param11;
	param11.push_back(1);
	param11.push_back(2);
	int ret1 = objectBirthdayCandy.mostCandy(param10,param11);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 4;
	vector <int> param21;
	param21.push_back(43);
	param21.push_back(81);
	param21.push_back(17);
	param21.push_back(1);
	param21.push_back(9);
	int ret2 = objectBirthdayCandy.mostCandy(param20,param21);
	int need2 = 17;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 6;
	vector <int> param31;
	param31.push_back(7);
	int ret3 = objectBirthdayCandy.mostCandy(param30,param31);
	int need3 = 1;
	assert_eq(3,ret3,need3);

}
