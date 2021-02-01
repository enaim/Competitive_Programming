#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T abs(T x){
    if(x<0)    return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

bool func(char ch)
{
    if('A'<=ch && 'Z'>=ch)
        return true;
    return false;
}

bool func1(char ch)
{
    if('A'<=ch && 'Z'>=ch)
        return true;
    if('a'<=ch && 'z'>=ch)
        return true;
    if('0'<=ch && '9'>=ch)
        return true;

    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    string str;

    getline(cin,str);
    while(tks--)
    {
        int s,e,o,c,n,i;
        getline(cin,str);
        str = ' '+str;
        str = str+' ';
        n = str.size();
//        cout<<str<<endl;
        c = e = s = o = 0;

        for(i=1;i<n-3;i++)
        {
            if(!func1(str[i-1]) && func(str[i]) && func(str[i+1]) && func(str[i+2]) && !func1(str[i+3]))
            {
                if(str[i]=='C' && str[i+1]=='S'&& str[i+2]=='E')
                    c++;
                else if(str[i]=='E' && str[i+1]=='E'&& str[i+2]=='E')
                    e++;
                else if(str[i]=='S' && str[i+1]=='W'&& str[i+2]=='E')
                    s++;
                else
                    o++;
//                    cout<<i<<" "<<c<<" "<<s<<" "<<" "<<e<<" "<<o<<endl;
            }
        }

        if(c!=0 && s!=0 && e!=0)
            printf("Case %d: SUST Tech Fest\n",ks++);
        else if(c!=0 && s==0 && e==0 && o==0)
            printf("Case %d: SUST CSE Carnival\n",ks++);
        else
            printf("Case %d: Festival of SUST\n",ks++);
    }

    return 0;
}
