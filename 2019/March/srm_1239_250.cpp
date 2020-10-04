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

class MissingDwarf
{
public:
	int getHeight(vector <int> vec)
	{
	    int sum=0,i,ans;
	   sort(vec.begin(),vec.end());
	   for(i=0;i<6;i++)
        sum+=vec[i];
        sum+=(vec[5]+1);
        ans = vec[5]+1;
        if(sum%7!=0)
            ans = (((sum/7)+1)*7)-(sum-vec[5]-1);
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

	MissingDwarf objectMissingDwarf;

	//test case0
	vector <int> param00;
	param00.push_back(1);
	param00.push_back(2);
	param00.push_back(3);
	param00.push_back(4);
	param00.push_back(5);
	param00.push_back(6);
	int ret0 = objectMissingDwarf.getHeight(param00);
	int need0 = 7;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(6);
	param10.push_back(5);
	param10.push_back(4);
	param10.push_back(3);
	param10.push_back(2);
	param10.push_back(1);
	int ret1 = objectMissingDwarf.getHeight(param10);
	int need1 = 7;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(10);
	param20.push_back(10);
	param20.push_back(20);
	param20.push_back(20);
	param20.push_back(30);
	param20.push_back(30);
	int ret2 = objectMissingDwarf.getHeight(param20);
	int need2 = 34;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(7);
	param30.push_back(7);
	param30.push_back(7);
	param30.push_back(7);
	param30.push_back(7);
	param30.push_back(7);
	int ret3 = objectMissingDwarf.getHeight(param30);
	int need3 = 14;
	assert_eq(3,ret3,need3);

}
