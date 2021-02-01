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

class SimpleWordGame
{
public:
	int points(vector <string> player, vector <string> dictionary)
	{
	    set<string>st;
	    for(int i=0;i< dictionary.size();i++)
        {
            for(int j=0;j<player.size();j++)
                if(dictionary[i] == player[j])
                    st.insert(player[j]);
        }

        int sum = 0;
        for(set<string>::iterator it = st.begin(); it != st.end(); it++)
            sum += (*it).size() * (*it).size();
        return sum;
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

	SimpleWordGame objectSimpleWordGame;

	//test case0
	vector <string> param00;
	param00.push_back("apple");
	param00.push_back("orange");
	param00.push_back("strawberry");
	vector <string> param01;
	param01.push_back("strawberry");
	param01.push_back("orange");
	param01.push_back("grapefruit");
	param01.push_back("watermelon");
	int ret0 = objectSimpleWordGame.points(param00,param01);
	int need0 = 136;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("apple");
	vector <string> param11;
	param11.push_back("strawberry");
	param11.push_back("orange");
	param11.push_back("grapefruit");
	param11.push_back("watermelon");
	int ret1 = objectSimpleWordGame.points(param10,param11);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("orange");
	param20.push_back("orange");
	vector <string> param21;
	param21.push_back("strawberry");
	param21.push_back("orange");
	param21.push_back("grapefruit");
	param21.push_back("watermelon");
	int ret2 = objectSimpleWordGame.points(param20,param21);
	int need2 = 36;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("lidi");
	param30.push_back("o");
	param30.push_back("lidi");
	param30.push_back("gnbewjzb");
	param30.push_back("kten");
	param30.push_back("ebnelff");
	param30.push_back("gptsvqx");
	param30.push_back("rkauxq");
	param30.push_back("rkauxq");
	param30.push_back("kfkcdn");
	vector <string> param31;
	param31.push_back("nava");
	param31.push_back("wk");
	param31.push_back("kfkcdn");
	param31.push_back("lidi");
	param31.push_back("gptsvqx");
	param31.push_back("ebnelff");
	param31.push_back("hgsppdezet");
	param31.push_back("ulf");
	param31.push_back("rkauxq");
	param31.push_back("wcicx");
	int ret3 = objectSimpleWordGame.points(param30,param31);
	int need3 = 186;
	assert_eq(3,ret3,need3);

}
