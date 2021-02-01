#include<bits/stdc++.h>
using namespace std;

/// read the question correctly (is y a vowel?)
/// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)

const int mx =  1234567;
const double exp1 =  1e-6;
const int md =  1e9+7;
typedef long long ll;

int ar[mx],xar[mx],uses[mx];
ll arr[mx];
int tab[1000][1000];
string st[1000];
int ar1[mx],ar2[mx];
map<int ,int>mpii;
map<int ,char>mpic;
map<char ,int>mpci;

ll phi[10000005],mark[10000005];

void Phi(){
    int n = 10000000;
    for(int i = 1; i <= n; i++){
        phi[i] = i;
    }

    phi[1] = 1;
    mark[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!mark[i]){
            for(int j = i; j <= n; j+=i){
                mark[j] = (ll)i;
                phi[j] = (ll)phi[j] / i*(i-1);
            }
        }

    }

}
ll ans[10000005];

int main(){

    int tk=1,n,m=0;
    ll v,p;
    int cs = 1;
//    freopen("in.txt","r", stdin);
//    freopen("out.txt","w", stdout);
    Phi();
    for(int i = 1; i <= 10000000; i++){
        ans[i] = ans[i-1] + phi[i];
    }

    scanf("%d",&tk);
    while(tk--){
         scanf("%lld%lld",&v,&p);
         ll lo = 1, hi = v,mid;
         ll res = -1;
         if(p==1) {
             printf("Case %d: %lld\n",cs++,v);
             continue;
         }

         while(lo<=hi){

            mid = (lo+hi)/2;
            int x = (int)mid;
            if(ans[x] < p){
                lo = mid + 1;
            }else{
                hi = mid - 1;
                res = mid;
            }
         }
         if(res==-1){
            printf("Case %d: -1\n",cs++);
            continue;
         }
        printf("Case %d: %lld\n",cs++,(v/res));


    }

    return 0;
}
