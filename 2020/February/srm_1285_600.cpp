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

class StringTransformationEasy
{
public:
	string getResult(string s, string t)
	{
	    string format1="",format2="";
	    vector<int>vec1,vec2;

	    int cnt,i;
	    for(i=0;i<s.size();i++)
        {
            if(i==0)
            {
                cnt = 1;
                format1+=s[i];
                continue;
            }
            else if(s[i-1]!=s[i])
            {
                format1+=s[i];
                vec1.push_back(cnt);
                cnt = 1;
            }
            else
                cnt++;
        }
        vec1.push_back(cnt);

        for(i=0;i<t.size();i++)
        {
            if(i==0)
            {
                cnt = 1;
                format2+=t[i];
                continue;
            }
            else if(t[i-1]!=t[i])
            {
                format2+=t[i];
                vec2.push_back(cnt);
                cnt = 1;
            }
            else
                cnt++;
        }
        vec2.push_back(cnt);

        if(format1!=format2 || vec1.size()!=vec2.size())
            return "NO";

        if(format1.size()==1 && t!=s)
            return "NO";

        for(i=0;i<vec2.size();i++)
        {
            if(vec1[i]>=vec2[i] && (vec1[i]-vec2[i])%2==0)
                continue;
            return "NO";
        }
        return "YES";
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

	StringTransformationEasy objectStringTransformationEasy;

	//test case0
	string param00 = "RGGGRRRG";
	string param01 = "RGRG";
	string ret0 = objectStringTransformationEasy.getResult(param00,param01);
	string need0 = "YES";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "RRR";
	string param11 = "RRR";
	string ret1 = objectStringTransformationEasy.getResult(param10,param11);
	string need1 = "YES";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "RRRGGRRRRGGG";
	string param21 = "RGGRRRRG";
	string ret2 = objectStringTransformationEasy.getResult(param20,param21);
	string need2 = "YES";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "RRGG";
	string param31 = "RRGGGG";
	string ret3 = objectStringTransformationEasy.getResult(param30,param31);
	string need3 = "NO";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "GGGG";
	string param41 = "GG";
	string ret4 = objectStringTransformationEasy.getResult(param40,param41);
	string need4 = "NO";
	assert_eq(4,ret4,need4);

}
