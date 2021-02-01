#include<iostream>
using namespace std;
struct point{
    int X,Y;
};
int Abs(int x){
    int diff=x;
    if(diff<0)diff*=(-1);
    return diff;
}
point arr[100];
int n,All;
int Dis(int i,int j){
    return Abs(arr[i].X-arr[j].X)+Abs(arr[i].Y-arr[j].Y);
}
int Min(int a,int b){
    return (a<b)? a:b;
}
int go(int bitmask, int prev){
    if(prev==n)// nth point neya ses
    {
        if(bitmask!=All)return 1e9;
        else return Dis(prev,n+1);
    }
    int ret=1e9;
    for(int i=1;i<=n;i++){
        if(!(bitmask&(1<<i))){
            ret=Min(ret,Dis(prev,i)+go(bitmask|(1<<i),i));
        }
    }
    return ret;
}
int main(){
    cin>>n;
    for(int i=0;i<=n+1;i++){
        cin>>arr[i].X>>arr[i].Y;
    }
    All=(1<<(n+1))-1;
    int res=go(1,0);// bitmask, previous point has taken
    cout<<res<<endl;
}
