#include <bits/stdc++.h>
using namespace std;


const int SIZE = 200010;
int ar[SIZE];
int Tree[SIZE*4];

void update(int l,int r,int node_no,int pos)
{
    if(l==pos && r==pos)
    {
        Tree[node_no]= ar[pos];
        return ;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(l,mid,node_no*2,pos);
    else
        update(mid+1,r,(node_no*2)+1,pos);
    Tree[node_no] = max(Tree[node_no*2],Tree[(node_no*2)+1]);
}

int Query(int l,int r,int node_no,int s,int e)
{
    if(l==s && r==e)
        return Tree[node_no];
    int mid = (l+r)/2;
    if(e<=mid)
        return Query(l,mid,node_no*2,s,e);
    else if(s>mid)
        return Query(mid+1,r,(node_no*2)+1,s,e);
    else
    {
        int q1 = Query(l,mid,(node_no*2),s,mid);
        int q2 = Query(mid+1,r,(node_no*2)+1,mid+1,e);
        return max(q1,q2);
    }
}


struct node{
    int duration,power;
};

bool compare(node a,node b)
{
    if(a.power==b.power)
        return a.duration>b.duration;
    return a.power>b.power;
}

int endurance[200010];
node hero[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,k,n,m,last,mn,mx;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        mn = mx = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            mn = max(mn,ar[i]);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&hero[i].power,&hero[i].duration);
            mx = max(mx,hero[i].power);
        }
        if(mn>mx)
        {
            printf("-1\n");
            continue;
        }

        for(i=0;i<n*4;i++)
            Tree[i]=-1000;
        for(i=1;i<=n;i++)
            update(1,n,1,i);

        sort(&hero[1],&hero[m+1],compare);
        last = 0;
        j = 1;
        mx = 0;
        mn = 2e9;
        for(i=1;i<=m;i++)
        {
            if(last<hero[i].duration)
            {
                for(k=j;k<=hero[i].duration;k++)
                    endurance[k]=hero[i].power;
                j = k;
                last = hero[i].duration;
            }
            mx = max(mx,hero[i].duration);
            mn = min(mn,hero[i].duration);
        }

        int temp,ans,left,right,mid,cnt = 0;
        i = 1;
        while(i<=n)
        {
            left = mn;
            right = mx;
            while(left<=right)
            {
                mid = (left+right)/2;
                last = min(n,i+mid-1);
                ans = Query(1,n,1,i,last);
                if(ans>endurance[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            temp = left - 1;
            last =  min(n,i+temp-1);
            ans = Query(1,n,1,i,last);
            if(endurance[temp]>=ans)
            {
                cnt++;
                i+=temp;
            }
            else
                break;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
