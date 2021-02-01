#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

struct Vtx{
    int no,w;

    Vtx(int no=0,int w=0){
        this->no = no;
        this->w = w;
    }

    // Me < notMe
    bool operator < (const Vtx& notMe)const {
        return w > notMe.w;
    }

    void print(){
        cout<<"No: "<<no<<" w: "<<w<<endl;
    }
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,t,val;

    Vtx A,B(10,1000);
    A.no=11;
    A.w = 100;
    A.print();

    B = Vtx(10,100000);
    B.print();


    while(cin>>n)
    {
        priority_queue<int>pq;

        while(n--)
        {
            cin>>t;
            if(t==1)
            {
                cout<<"Insert: ";
                cin>>val;
                pq.push(val);
            }
            else if(t==0){
                if(!pq.empty())
                {
                    cout<<"Top: "<<pq.top()<<endl;
                }
                else puts("Empty!");
            }
            else {
                if(!pq.empty()) pq.pop();
            }

            deb(pq.size());
        }
    }

    return 0;
}
