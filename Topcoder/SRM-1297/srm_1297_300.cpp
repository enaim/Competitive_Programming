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

class PosNegDice
{
public:
	vector <int> evaluateRoll(int T, vector <int> pos, vector <int> neg)
	{
	    int i,x,y,mn;
	    int ar[7]={0};
	    int br[7]={0};
	    for(i=0;i<pos.size();i++)
            ar[pos[i]]++;
        for(i=0;i<neg.size();i++)
            br[neg[i]]++;

	    for(i=1;i<=6;i++)
        {
            mn = min(ar[i],br[i]);
            ar[i]-=mn;
            br[i]-=mn;
        }
        x = 0;
        for(i=1;i<=6;i++)
        {
            if(ar[i] && i<=T)
                x = 1;
        }
        y = 0;
        for(i=1;i<=6;i++)
        {
            y+=br[i];
        }
        vector<int>vec;
        vec.push_back(x);
        vec.push_back(y);
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

	PosNegDice objectPosNegDice;

	//test case0
	int param00 = 1;
	vector <int> param01;
	param01.push_back(1);
	param01.push_back(6);
	param01.push_back(2);
	vector <int> param02;
	param02.push_back(6);
	vector <int> ret0 = objectPosNegDice.evaluateRoll(param00,param01,param02);
	vector <int> need0;
	need0.push_back(1);
	need0.push_back(0);
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 4;
	vector <int> param11;
	vector <int> param12;
	vector <int> ret1 = objectPosNegDice.evaluateRoll(param10,param11,param12);
	vector <int> need1;
	need1.push_back(0);
	need1.push_back(0);
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 4;
	vector <int> param21;
	param21.push_back(5);
	param21.push_back(6);
	param21.push_back(6);
	param21.push_back(5);
	param21.push_back(5);
	vector <int> param22;
	vector <int> ret2 = objectPosNegDice.evaluateRoll(param20,param21,param22);
	vector <int> need2;
	need2.push_back(0);
	need2.push_back(0);
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 5;
	vector <int> param31;
	param31.push_back(3);
	param31.push_back(6);
	param31.push_back(3);
	param31.push_back(6);
	vector <int> param32;
	param32.push_back(3);
	param32.push_back(3);
	param32.push_back(1);
	param32.push_back(3);
	param32.push_back(6);
	param32.push_back(3);
	param32.push_back(5);
	vector <int> ret3 = objectPosNegDice.evaluateRoll(param30,param31,param32);
	vector <int> need3;
	need3.push_back(0);
	need3.push_back(4);
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 4;
	vector <int> param41;
	param41.push_back(4);
	param41.push_back(5);
	param41.push_back(6);
	vector <int> param42;
	param42.push_back(1);
	param42.push_back(2);
	param42.push_back(3);
	vector <int> ret4 = objectPosNegDice.evaluateRoll(param40,param41,param42);
	vector <int> need4;
	need4.push_back(1);
	need4.push_back(3);
	assert_eq(4,ret4,need4);

}
