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

class AveragePrice
{
public:
	double nonDuplicatedAverage(vector <int> vec)
	{
	    set<int>st;
        int n = vec.size(),i;
        for(i=0;i<n;i++)
            st.insert(vec[i]);
        n = st.size();
        double sum = 0.0;
        for(auto it:st)
            sum+=it;
        return (sum/n);
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

	AveragePrice objectAveragePrice;

	//test case0
	vector <int> param00;
	param00.push_back(10);
	param00.push_back(20);
	param00.push_back(10);
	double ret0 = objectAveragePrice.nonDuplicatedAverage(param00);
	double need0 = 15.0;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(1);
	param10.push_back(2);
	param10.push_back(3);
	param10.push_back(4);
	param10.push_back(5);
	double ret1 = objectAveragePrice.nonDuplicatedAverage(param10);
	double need1 = 3.0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(10);
	param20.push_back(10);
	param20.push_back(10);
	param20.push_back(10);
	param20.push_back(10);
	param20.push_back(10);
	double ret2 = objectAveragePrice.nonDuplicatedAverage(param20);
	double need2 = 10.0;
	assert_eq(2,ret2,need2);

}
