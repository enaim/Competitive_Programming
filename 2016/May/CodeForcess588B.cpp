#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n,i;

    cin>>n;
    int b=sqrt(n);

    for(i=b; i>1; i--)
    {
        while(n%(i*i)==0)
        {
            n=n/i;
        }
    }
    cout<<n<<endl;

    return 0;
}
