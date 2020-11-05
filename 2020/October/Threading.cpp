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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


#include<thread>
#include<chrono>
#include<mutex>

std::mutex mutexPrint;
std::mutex mutexSet;

set<string>st;

void Print(string out)
{
    mutexPrint.lock();

    cout<<out<<endl;


    mutexSet.lock();
    st.insert(out);
    mutexSet.unlock();


    mutexPrint.unlock();
}

bool Find(string key)
{
    mutexSet.lock();

    bool bIsExist = (st.find(key)!=st.end());

    mutexSet.unlock();

    return bIsExist;
}

void run(int no)
{

    int cnt = 0;
    while(cnt<10)
    {
        cnt++;
        Print( string("[Thread No ") + to_string(no) + " : "+ to_string(cnt));

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Ask(int no)
{
    int cnt = 0;
    while(cnt<10)
    {
        if(Find("[Thread No 1 : "+to_string(no)))
            Print(to_string(no) +"    ->  FOUND!!!!!");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        cnt++;
    }
}


int main()
{
    thread threadOne(run, 1);

    thread threadTwo(run, 2);

    thread threadThree(Ask, 5);

    Print("Three running...");
    threadOne.join();
    threadTwo.join();


    printf("END\n");

    return 0;
}
