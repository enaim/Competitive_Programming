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

string str[52];
vector<string>vec;

class ThreeNeighbors
{
public:
	vector <string> construct(int k)
	{
	    vec.clear();
        int n = 50,i,j;
        for(i=0;i<n;i++)
        {
            str[i]="";
            for(j=0;j<n;j++)
                str[i]+='.';
        }
        j = 1;
        while(k)
        {
            for(i=0;i<48 && k>1;i++)
            {
                str[i][j]='X';
                str[i+1][j]='X';
                str[i+2][j]='X';
                k-=2;
            }
            j+=3;
            if(k==1)
            {
                str[0][49]='X';
                str[1][49]='X';
                str[2][49]='X';
                k = 0;
            }
        }

        for(i=0;i<50;i++)
            vec.push_back(str[i]);
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
	ThreeNeighbors objectThreeNeighbors;

	//test case0
	int param00 = 2;
	vector <string> ret0 = objectThreeNeighbors.construct(param00);
	vector <string> need0;
	need0.push_back(".....");
	need0.push_back(".XX..");
	need0.push_back(".X.X.");
	need0.push_back(".X...");
	need0.push_back(".....");
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 6;
	vector <string> ret1 = objectThreeNeighbors.construct(param10);
	vector <string> need1;
	need1.push_back("........");
	need1.push_back(".XXX..X.");
	need1.push_back("..X..X..");
	need1.push_back("..X..X..");
	need1.push_back("..X...X.");
	need1.push_back("........");
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 1;
	vector <string> ret2 = objectThreeNeighbors.construct(param20);
	vector <string> need2;
	need2.push_back("XXXX");
	need2.push_back("XXXX");
	need2.push_back(".XXX");
	assert_eq(2,ret2,need2);

}
