#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>vec{30,40,30,10,20,25,50};
    sort(vec.begin(),vec.end());

    vector<int>:: iterator it;

    it = lower_bound(vec.begin(),vec.end(),30);
    cout<<it-vec.begin()<<endl;

    it = upper_bound(vec.begin(),vec.end(),30);
    cout<<it-vec.begin()<<endl;

    return 0;
}
