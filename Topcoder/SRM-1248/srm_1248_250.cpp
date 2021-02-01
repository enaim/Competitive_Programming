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

class MilkConsumption
{
public:
	vector <int> findMaxRegion(vector <int> p, vector <int> t)
	{
	    double mx = (double)t[0]/(double)p[0];
	    int ind = 0;
	    int sz = p.size();
	    for(int i=1;i<sz;i++)
        {
            double x = (double)t[i]/(double)p[i];
            if(mx<x)
            {
                ind = i;
                mx = x;
            }
        }
        vector<int>ans;
        ans.push_back(ind);
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

	MilkConsumption objectMilkConsumption;

	//test case0
	vector <int> param00;
	param00.push_back(10);
	param00.push_back(10);
	param00.push_back(10);
	param00.push_back(10);
	vector <int> param01;
	param01.push_back(47);
	param01.push_back(47);
	param01.push_back(47);
	param01.push_back(47);
	vector <int> ret0 = objectMilkConsumption.findMaxRegion(param00,param01);
	vector <int> need0;
	need0.push_back(2);
	need0.push_back(3);
	need0.push_back(0);
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(1234567);
	param10.push_back(2345678);
	param10.push_back(3456789);
	param10.push_back(4567890);
	vector <int> param11;
	param11.push_back(2345678);
	param11.push_back(3456789);
	param11.push_back(4567890);
	param11.push_back(5678901);
	vector <int> ret1 = objectMilkConsumption.findMaxRegion(param10,param11);
	vector <int> need1;
	need1.push_back(0);
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(98);
	param20.push_back(120);
	param20.push_back(40);
	param20.push_back(135);
	param20.push_back(40);
	vector <int> param21;
	param21.push_back(4606);
	param21.push_back(5167);
	param21.push_back(1880);
	param21.push_back(1351);
	param21.push_back(1879);
	vector <int> ret2 = objectMilkConsumption.findMaxRegion(param20,param21);
	vector <int> need2;
	need2.push_back(0);
	need2.push_back(2);
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(9227465);
	param30.push_back(14930352);
	vector <int> param31;
	param31.push_back(5702887);
	param31.push_back(9227465);
	vector <int> ret3 = objectMilkConsumption.findMaxRegion(param30,param31);
	vector <int> need3;
	need3.push_back(1);
	assert_eq(3,ret3,need3);

}
