#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int FLAG_SIZE = 100000100;
const int PRIME_SIZE = 5761500;

ll flag[FLAG_SIZE/64+10];
int prime[PRIME_SIZE],ind;

void sieve()//1 indexed
{
    long long i,j,k;
    for(i=3;i<FLAG_SIZE;i+=2)
         if(!(flag[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<FLAG_SIZE;j+=2*i)
                    flag[j/64]|=(1LL<<(j%64));

    prime[ind++]=2;
    for (int i=3;i<FLAG_SIZE;i+=2)
        if(!(flag[i/64]&(1LL<<(i%64))))
            prime[ind++] = i;
//    for(i=1;i<10;i++)
//        printf("%d\n",prime[i]);
//    printf("%d\n",ind);
}

int main()
{
    sieve();

    return 0;
}
