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


class SeventhPowers
{
public:
	string reconstructA(int b)
	{
        int i;
        int ar[10],j;
        string x="";
        for(i=1;i<=9;i++)
        {
            ar[i]=1;
            for(j=1;j<=7;j++)
                ar[i]*=i;
        }

        i = 9;
        t = 9;
        int cnt=0;
        int temp = b;
        while(b!=0)
        {
            if(ar[i]>b)
                i--;
            else
            {
                cnt++;
                b-=ar[i];
                if(i==1)
                    x+="1";
                if(i==2)
                    x+="2";
                if(i==3)
                    x+="3";
                if(i==4)
                    x+="4";
                if(i==5)
                    x+="5";
                if(i==6)
                    x+="6";
                if(i==7)
                    x+="7";
                if(i==8)
                    x+="8";
                if(i==9)
                    x+="9";
            }
            if(cnt>500)
            {
                cnt = 0;
                t--;
                i = t;
                b = temp;
                x = "";
            }
        }
        return x;
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

	SeventhPowers objectSeventhPowers;

	//test case0
	int param00 = 839927;
	string ret0 = objectSeventhPowers.reconstructA(param00);
	string need0 = "407";
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 130;
	string ret1 = objectSeventhPowers.reconstructA(param10);
	string need1 = "121";
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 43740;
	string ret2 = objectSeventhPowers.reconstructA(param20);
	string need2 = "33333333333333333333";
	assert_eq(2,ret2,need2);

}
