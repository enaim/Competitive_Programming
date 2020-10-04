#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;


class Reroll
{
public:
	int minimumDice(int t, vector <int> ar)
	{
	    int i,n = ar.size(),sum=0,cnt=0;

	    sort(ar.begin(),ar.end());

	    for(i=0;i<n;i++)
            sum+=ar[i];

        if(sum==t)
            return 0;
        else if(sum>t)
        {
            for(i=n-1;i>=0;i--)
            {
                if(sum - (ar[i]-1) <= t)
                    return cnt+1;
                else
                    sum -= (ar[i]-1) , cnt++;
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(sum + (6-ar[i]) >= t)
                    return cnt+1;
                else
                    sum += (6-ar[i]) , cnt++;
            }
        }
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

	Reroll objectReroll;

	//test case0
	int param00 = 7;
	vector <int> param01;
	param01.push_back(2);
	param01.push_back(6);
	param01.push_back(4);
	int ret0 = objectReroll.minimumDice(param00,param01);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	vector <int> param11;
	param11.push_back(4);
	param11.push_back(2);
	param11.push_back(4);
	param11.push_back(5);
	int ret1 = objectReroll.minimumDice(param10,param11);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 42;
	vector <int> param21;
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(6);
	int ret2 = objectReroll.minimumDice(param20,param21);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 42;
	vector <int> param31;
	param31.push_back(1);
	param31.push_back(3);
	param31.push_back(5);
	param31.push_back(3);
	param31.push_back(6);
	param31.push_back(4);
	param31.push_back(2);
	int ret3 = objectReroll.minimumDice(param30,param31);
	int need3 = 6;
	assert_eq(3,ret3,need3);

	int param40 = 20;
	vector <int> param41;

	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);
	param41.push_back(6);

	int ret4 = objectReroll.minimumDice(param40,param41);
	int need4 = 20;
	assert_eq(4,ret4,need4);


}
