#include<iostream>
using namespace std;
int used[20],number[20],N;
void Permutation(int pos)
{
    if(pos==N+1)
    {
        for(int i=1;i<=N;i++)cout<<number[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(!used[i]){
            used[i]=1;
            number[pos]=i;
            Permutation(pos+1);
            used[i]=0;
        }
    }
}
int main()
{
    N=5;
    Permutation(1);
}
