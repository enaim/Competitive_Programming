#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>


using namespace std;

int vis[53][53];
struct node{
    int x,y,l,m;
};


class Tunnel
{
public:
	int minKeystrokes(vector <string> str, int rate)
	{
	    int i,j;
	    for(i=0;i<53;i++)
            for(j=0;j<53;j++)
                vis[i][j]=0;

	    int r = str.size();
	    int c = str[0].size();
	    node u,v;
        for(i=0;i<c;i++)
            if(str[0][i]=='v')
            {
                v.x = 0;
                v.y = i;
                v.l = 0;
                v.m = 0;
            }
        queue<node>Q;
        Q.push(v);
        vis[v.x][v.y]=1;
        int mn = 100000000;
        while(!Q.empty())
        {
            u = Q.front();
            Q.pop();
            if(u.x==r-1)
            {
                mn = min(mn,u.m);
                continue;
            }
            if(u.l==0)
            {
                for(i=1;i<=rate;i++)
                {
                    if(u.y+i==c)
                        break;
                    if(str[u.x][u.y+i]=='#')
                        break;
                    v.x = u.x;
                    v.y = u.y+i;
                    v.l = 1;
                    v.m = u.m+i;
                    if(vis[v.x][v.y]==0)
                        Q.push(v);
                    vis[v.x][v.y]=1;
                }
                for(i=1;i<=rate;i++)
                {
                    if(u.y-i==-1)
                        break;
                    if(str[u.x][u.y-i]=='#')
                        break;
                    v.x = u.x;
                    v.y = u.y-i;
                    v.l = 1;
                    v.m = u.m+i;
                    if(vis[v.x][v.y]==0)
                        Q.push(v);
                    vis[v.x][v.y]=1;
                }
            }
            if(str[u.x+1][u.y]=='#')
                continue;
            v.x = u.x+1;
            v.y = u.y;
            v.l = 0;
            v.m = u.m;
            if(vis[v.x][v.y]==0)
                Q.push(v);
            vis[v.x][v.y]=1;
        }
        if(mn == 100000000)
            return -1;
        else
            return mn;
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

	Tunnel objectTunnel;

	//test case0
	vector <string> param00;
	param00.push_back("##..v..##");
	param00.push_back("###.....#");
	param00.push_back("#####...#");
	param00.push_back("####...##");
	param00.push_back("###..####");
	param00.push_back("#.......#");
	param00.push_back("#...#####");
	int param01 = 2;
	int ret0 = objectTunnel.minKeystrokes(param00,param01);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("#.v.#");
	param10.push_back("##..#");
	param10.push_back("###.#");
	param10.push_back("#...#");
	int param11 = 0;
	int ret1 = objectTunnel.minKeystrokes(param10,param11);
	int need1 = -1;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("#v....#");
	param20.push_back("###...#");
	param20.push_back("#####.#");
	int param21 = 1;
	int ret2 = objectTunnel.minKeystrokes(param20,param21);
	int need2 = -1;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("#v....#");
	param30.push_back("###...#");
	param30.push_back("#####.#");
	int param31 = 2;
	int ret3 = objectTunnel.minKeystrokes(param30,param31);
	int need3 = 4;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("#...v.#");
	int param41 = 47;
	int ret4 = objectTunnel.minKeystrokes(param40,param41);
	int need4 = 0;
	assert_eq(4,ret4,need4);

}
