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
#define sqr(a)    ((a)*(a))
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

double dist;

struct coordinate
{
    double x;
    double y;
    void scan(){
        cin>>x>>y;
    }
};

coordinate make_vector(coordinate point1 ,coordinate point2)
{
    coordinate AB;
    AB.x = point2.x - point1.x;
    AB.y = point2.y - point1.y;

    return AB;
}

int Dot(coordinate A,coordinate B)
{
    return (A.x * B.x) + (A.y * B.y);
}

double Distance(coordinate point1,coordinate point2)
{
    return fabs(sqrt(sqr(point1.x - point2.x) + sqr(point1.y - point2.y)));
}

double absolute(coordinate AB)
{
    return sqrt((AB.x*AB.x) + (AB.y*AB.y));
}

double Length(coordinate AB,coordinate AP)
{
    int x = Dot(AB,AP);
    double y = absolute(AB);

    return  x / y;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double temp,ab,l;
    int result1,result2,N;
    coordinate t,Uv,AB,AP,BA,BP,mini,point1,point2,target;

    while(3 == scanf("%lf%lf%d",&target.x,&target.y,&N))
    {
        dist = OO;
        point1.scan();

        while(N--)
        {
            point2.scan();
            AB = make_vector(point1,point2);
            AP = make_vector(point1,target);

            result1 = Dot(AB,AP);

            BA = make_vector(point2,point1);
            BP = make_vector(point2,target);

            result2 = Dot(BA,BP);
            if(result1 < 0)
            {
                temp = Distance(target,point1);
                if(temp<dist)
                {
                    dist = temp;
                    mini.x = point1.x;
                    mini.y = point1.y;
                }
            }

            else if(result2 < 0)
            {
                temp = Distance(target,point2);
                if(temp<dist)
                {
                    dist = temp;
                    mini.x = point2.x;
                    mini.y = point2.y;
                }
            }

            else
            {
                l = Length(AB,AP);
                ab = absolute(AB);

                Uv.x = AB.x/ab;
                Uv.y = AB.y/ab;

                t.x = point1.x + (Uv.x*l);
                t.y = point1.y + (Uv.y*l);

                temp = Distance(t,target);
                if(temp<dist)
                {
                    dist = temp;
                    mini.x = t.x;
                    mini.y = t.y;
                }
            }
            point1.x = point2.x;
            point1.y = point2.y;
        }

        printf("%.4lf\n%.4lf\n",mini.x,mini.y);
    }

    return 0;
}
