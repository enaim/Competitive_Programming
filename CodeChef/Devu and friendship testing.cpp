#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>

using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,x,n,i;
    set<int>st;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            st.insert(x);
        }
        x = st.size();

        printf("%d\n",x);
    }

    return 0;
}
