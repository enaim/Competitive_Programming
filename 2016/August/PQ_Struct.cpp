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

    void take(){
        cin>>no>>w;
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


    cin>>n;
    {
        priority_queue<Vtx>pq;

        while(n--)
        {
            cin>>t;
            if(t==1)
            {
                cout<<"Insert: ";
                B.take();
                pq.push(B);
            }
            else if(t==0){
                if(!pq.empty())
                {
                    Vtx top = pq.top();
                    top.print();
                }
                else puts("Empty! [Underflow]");
            }
            else {
                if(!pq.empty())
                {
                    puts("Deleted!");
                    pq.pop();

                }
                else puts("Empty! [Underflow]");
            }

            deb(pq.size());
        }
    }

    return 0;
}
