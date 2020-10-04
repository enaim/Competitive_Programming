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

class PingPongQueue
{
public:
	vector <int> whoPlaysNext(vector <int> skills, int N, int K)
	{
	    int mx = skills[0];
	    int a,i=1,j,temp,L,W;
	    map<int,int>mp;
	    queue<int>Q;
	    Q.empty();
	    mp.empty();

	    for(j=0;j<K;j++)
        {
            if(i!=skills.size())
                a = skills[i++];
            else
            {
                a = Q.front();
                Q.pop();
            }

            if(mx<a)
            {
                temp = a;
                a = mx;
                mx = temp;
            }

            L = a;
            W = mx;
            Q.push(a);
            mp[a]=0;
            mp[mx]++;

            if(mp[mx]==N)
            {
                Q.push(mx);
                mp[mx] = 0;
                if(i==skills.size())
                {
                    mx = Q.front();
                    Q.pop();
                }
                else
                    mx = skills[i++];
            }
        }

        vector<int>ret(2);
        ret[0] = L;
        ret[1] = W;
        return ret;
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

	PingPongQueue objectPingPongQueue;

	//test case0
	vector <int> param00;
	param00.push_back(1);
	param00.push_back(2);
	param00.push_back(3);
	int param01 = 2;
	int param02 = 2;
	vector <int> ret0 = objectPingPongQueue.whoPlaysNext(param00,param01,param02);
	vector <int> need0;
	need0.push_back(2);
	need0.push_back(3);
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(1);
	param10.push_back(2);
	param10.push_back(3);
	int param11 = 2;
	int param12 = 4;
	vector <int> ret1 = objectPingPongQueue.whoPlaysNext(param10,param11,param12);
	vector <int> need1;
	need1.push_back(1);
	need1.push_back(2);
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(49);
	param20.push_back(24);
	param20.push_back(26);
	param20.push_back(12);
	param20.push_back(5);
	param20.push_back(33);
	param20.push_back(25);
	param20.push_back(30);
	param20.push_back(35);
	param20.push_back(41);
	param20.push_back(46);
	param20.push_back(23);
	param20.push_back(21);
	param20.push_back(3);
	param20.push_back(38);
	param20.push_back(43);
	param20.push_back(11);
	param20.push_back(19);
	param20.push_back(34);
	param20.push_back(29);
	param20.push_back(20);
	param20.push_back(32);
	param20.push_back(39);
	param20.push_back(7);
	param20.push_back(50);
	int param21 = 10;
	int param22 = 399;
	vector <int> ret2 = objectPingPongQueue.whoPlaysNext(param20,param21,param22);
	vector <int> need2;
	need2.push_back(12);
	need2.push_back(50);
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(30);
	param30.push_back(12);
	int param31 = 34;
	int param32 = 80;
	vector <int> ret3 = objectPingPongQueue.whoPlaysNext(param30,param31,param32);
	vector <int> need3;
	need3.push_back(12);
	need3.push_back(30);
	assert_eq(3,ret3,need3);

	return 0;

}
