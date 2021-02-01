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

vector<int>vec,v;

int cnt = 1,t = 1;
int go(int sz,int kk)
{
    int i,j,f,x,k;
    if(kk==0)
        return 1;

    for(i=0;i<16;i++)
    {
        for(j=0;j<50;j++)
        {
            f = 0;
            for(k=0;k<sz;k+=2)
            {
                if(i==vec[k])
                {
                    f = 1;
                    break;
                }
                if(j == vec[k+1])
                {
                    f = 2;
                    break;
                }
                if(abs(vec[k]-i) == abs(vec[k+1]-j))
                {
                    f = 2;
                    break;
                }
            }

            if(f==1)
                break;
            if(f==2)
                continue;
            vec.push_back(i);
            vec.push_back(j);
            x = go(sz+2,kk-1);
            if(x==1)
                return 1;
            vec.erase(vec.begin()+sz);
            vec.erase(vec.begin()+sz+1);
        }
    }
    return 0;
}


class SixteenQueens
{
public:
	vector <int> addQueens(vector <int> row, vector <int> col, int add)
	{
	    v.clear();
	    vec.clear();
	    int sz = row.size(),i;
	    for(i=0;i<sz;i++)
        {
            vec.push_back(row[i]);
            vec.push_back(col[i]);
        }
        if(add==0)
            return v;

        go(sz*2,add);
        int szz = vec.size();
        for(i=sz*2;i<szz;i++)
            v.push_back(vec[i]);
        sz = v.size();
        return v;
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

	SixteenQueens objectSixteenQueens;

	//test case0
	vector <int> param00;
	param00.push_back(3);
	vector <int> param01;
	param01.push_back(5);
	int param02 = 1;
	vector <int> ret0 = objectSixteenQueens.addQueens(param00,param01,param02);
	vector <int> need0;
	need0.push_back(0);
	need0.push_back(0);
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(0);
	vector <int> param11;
	param11.push_back(1);
	int param12 = 1;
	vector <int> ret1 = objectSixteenQueens.addQueens(param10,param11,param12);
	vector <int> need1;
	need1.push_back(4);
	need1.push_back(7);
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(0);
	vector <int> param21;
	param21.push_back(1);
	int param22 = 3;
	vector <int> ret2 = objectSixteenQueens.addQueens(param20,param21,param22);
	vector <int> need2;
	need2.push_back(4);
	need2.push_back(7);
	need2.push_back(15);
	need2.push_back(0);
	need2.push_back(49);
	need2.push_back(49);
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(14);
	param30.push_back(19);
	vector <int> param31;
	param31.push_back(3);
	param31.push_back(47);
	int param32 = 0;
	vector <int> ret3 = objectSixteenQueens.addQueens(param30,param31,param32);
	vector <int> need3;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	vector <int> param41;
	int param42 = 2;
	vector <int> ret4 = objectSixteenQueens.addQueens(param40,param41,param42);
	vector <int> need4;
	need4.push_back(0);
	need4.push_back(0);
	need4.push_back(1);
	need4.push_back(2);
	assert_eq(4,ret4,need4);

	//test case5
	vector <int> param50;
	param50.push_back(1);
	param50.push_back(2);
	param50.push_back(3);
	vector <int> param51;
	param51.push_back(7);
	param51.push_back(2);
	param51.push_back(19);
	int param52 = 1;
	vector <int> ret5 = objectSixteenQueens.addQueens(param50,param51,param52);
	vector <int> need5;
	need5.push_back(0);
	need5.push_back(1);
	assert_eq(5,ret5,need5);

}

