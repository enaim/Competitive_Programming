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

class ElevatorButtons
{
public:
	vector <int> nextStops(int cur, int dir, vector <int> b)
	{
	    vector<int>vec;
	    set<int>st;
	    sort(b.begin(),b.end());
	    int i,n = b.size();
	    if(dir==1)
        {
            for(i=0;i<n;i++)
            {
                if(b[i]>=cur)
                {
                    st.insert(b[i]);
                }
            }

            for(auto it:st)
                vec.push_back(it);
            st.clear();

            for(i=n-1;i>=0;i--)
            {
                if(b[i]<cur)
                    st.insert(-b[i]);
            }
            for(auto it:st)
                vec.push_back(abs(it));
        }
        else
        {
            for(i=n-1;i>=0;i--)
            {
                if(b[i]<=cur)
                    st.insert(-b[i]);
            }
            for(auto it:st)
                vec.push_back(abs(it));
            st.clear();
            for(i=0;i<n;i++)
            {
                if(b[i]>cur)
                    st.insert(b[i]);
            }
            for(auto it:st)
                vec.push_back(it);
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

	ElevatorButtons objectElevatorButtons;

	//test case0
	int param00 = 10;
	int param01 = 1;
	vector <int> param02;
	param02.push_back(7);
	param02.push_back(15);
	vector <int> ret0 = objectElevatorButtons.nextStops(param00,param01,param02);
	vector <int> need0;
	need0.push_back(15);
	need0.push_back(7);
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	int param11 = -1;
	vector <int> param12;
	param12.push_back(7);
	param12.push_back(15);
	vector <int> ret1 = objectElevatorButtons.nextStops(param10,param11,param12);
	vector <int> need1;
	need1.push_back(7);
	need1.push_back(15);
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 10;
	int param21 = -1;
	vector <int> param22;
	param22.push_back(47);
	param22.push_back(47);
	param22.push_back(47);
	param22.push_back(47);
	param22.push_back(47);
	vector <int> ret2 = objectElevatorButtons.nextStops(param20,param21,param22);
	vector <int> need2;
	need2.push_back(47);
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 500;
	int param31 = 1;
	vector <int> param32;
	param32.push_back(420);
	param32.push_back(570);
	param32.push_back(140);
	param32.push_back(230);
	param32.push_back(915);
	param32.push_back(820);
	param32.push_back(499);
	param32.push_back(820);
	param32.push_back(177);
	vector <int> ret3 = objectElevatorButtons.nextStops(param30,param31,param32);
	vector <int> need3;
	need3.push_back(570);
	need3.push_back(820);
	need3.push_back(915);
	need3.push_back(499);
	need3.push_back(420);
	need3.push_back(230);
	need3.push_back(177);
	need3.push_back(140);
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 1000;
	int param41 = -1;
	vector <int> param42;
	param42.push_back(0);
	vector <int> ret4 = objectElevatorButtons.nextStops(param40,param41,param42);
	vector <int> need4;
	need4.push_back(0);
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 600;
	int param51 = -1;
	vector <int> param52;
	param52.push_back(420);
	param52.push_back(570);
	param52.push_back(140);
	param52.push_back(230);
	param52.push_back(915);
	param52.push_back(820);
	param52.push_back(499);
	param52.push_back(820);
	param52.push_back(177);
	vector <int> ret5 = objectElevatorButtons.nextStops(param50,param51,param52);
	vector <int> need5;
	need5.push_back(570);
	need5.push_back(499);
	need5.push_back(420);
	need5.push_back(230);
	need5.push_back(177);
	need5.push_back(140);
	need5.push_back(820);
	need5.push_back(915);
	assert_eq(5,ret5,need5);

}
