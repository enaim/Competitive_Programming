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

bool check(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;
    return false;
}

class SyllableCountEstimator
{
public:
	int estimate(string str)
	{
	    int n = str.size();
	    int vowel = 0,i, cnt = 0;
	    for(i=0;i<n;i++)
        {
            if(check(str[i]))
                vowel++;
        }
        for(i=0;i<n-1;i++)
        {
            if(str[i]=='a' && str[i+1]=='u')
                cnt++;
            if(str[i]=='o' && str[i+1]=='a')
                cnt++;
            if(str[i]=='o' && str[i+1]=='o')
                cnt++;
        }
        for(i=0;i<n-2;i++)
        {
            if(str[i]=='i' && str[i+1]=='o' && str[i+2]=='u')
                cnt++;
        }
        if(str[n-1]=='e')
            cnt++;
        if(n>2 && str[n-1]=='e' && str[n-2]=='l' && !check(str[n-3]))
            vowel++;
        return max(1,vowel-cnt);
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

	SyllableCountEstimator objectSyllableCountEstimator;

	//test case0
	string param00 = "potato";
	int ret0 = objectSyllableCountEstimator.estimate(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "haul";
	int ret1 = objectSyllableCountEstimator.estimate(param10);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "gooooooal";
	int ret2 = objectSyllableCountEstimator.estimate(param20);
	int need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "rhythm";
	int ret3 = objectSyllableCountEstimator.estimate(param30);
	int need3 = 1;
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "e";
	int ret4 = objectSyllableCountEstimator.estimate(param40);
	int need4 = 1;
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "le";
	int ret5 = objectSyllableCountEstimator.estimate(param50);
	int need5 = 1;
	assert_eq(5,ret5,need5);

	//test case6
	string param60 = "various";
	int ret6 = objectSyllableCountEstimator.estimate(param60);
	int need6 = 3;
	assert_eq(6,ret6,need6);

	//test case7
	string param70 = "queued";
	int ret7 = objectSyllableCountEstimator.estimate(param70);
	int need7 = 4;
	assert_eq(7,ret7,need7);

	//test case8
	string param80 = "qwertyuiopasdfghjkl";
	int ret8 = objectSyllableCountEstimator.estimate(param80);
	int need8 = 5;
	assert_eq(8,ret8,need8);

	//test case9
	string param90 = "participle";
	int ret9 = objectSyllableCountEstimator.estimate(param90);
	int need9 = 4;
	assert_eq(9,ret9,need9);

	//test case10
	string param100 = "ukulele";
	int ret10 = objectSyllableCountEstimator.estimate(param100);
	int need10 = 3;
	assert_eq(10,ret10,need10);

}
