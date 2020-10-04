#include<iostream>
using namespace std;
int number[20];
int n=5,k=3;
void combination(int pos,int last){
    if(pos==k+1){
        for(int i=1;i<=k;i++)cout<<number[i];cout<<endl;
        return;
    }
    for(int i=last+1;i<=n-k+pos;i++){
        number[pos]=i;
        combination(pos+1,i);
    }
}
int main(){
    combination(1,0);
}
