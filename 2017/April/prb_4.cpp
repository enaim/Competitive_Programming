#include<bits/stdc++.h>
using namespace std;


int main()
{

    freopen("in.txt","r",stdin);

    int tks,ks=1;
    int x,n,m,a;

    char str[40];
    deque<int>dq;
    scanf("%d",&tks);
    int i;
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d%d",&n,&m);
         x = 0;
        for(i=0;i<m;i++)
        {
            scanf("%s%d",str,&a);

//            printf("x = %d\n",x);
            if(str[1] == 'u' && x==n)
            {
                printf("The queue is full\n");
            }
            else if(str[1] == 'o' && x==0)
            {
                printf("The queue is empty\n");
            }

            else if(strcmp(str,"pushLeft")==0)
            {
                dq.push_front(a);
                printf("Pushed in left: %d\n",a);
                x++;
            }
            else if(strcmp(str,"pushRight")==0)
            {
                dq.push_back(a);
                printf("Pushed in right: %d\n",a);
                x++;
            }
            else if(strcmp(str,"popLeft")==0)
            {
                int val = dq.front();
                dq.pop_front();
                printf("Popped from left: %d\n",val);
                x--;
            }
            else if(strcmp(str,"popRight")==0)
            {
                int val = dq.back();
                dq.pop_back();
                printf("Popped from right: %d\n",val);
                x--;
            }
        }
    }

    return 0;
}
