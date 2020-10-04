#include <stdio.h>
#include <string.h>
#include <math.h>


struct BT{

    int node;
    int value;
    int left_node_no;
    int right_node_no;
};


BT ar[100];
int cnt,i;

void binary_tree(int n,int x)
{
    if(n == ar[x].value)
    {
        printf("n: %d    ar[%d].value: %d \n",n,x,ar[x].value);
        printf("ok\n");
    }

    else if(n < ar[x].value)
    {
        if(ar[x].left_node_no == (-1))
        {
            ar[x].left_node_no =  ar[i].node;
            printf("ar[%d].left_node_no: %d\n",x,ar[x].left_node_no);
        }
        else
        {
//            printf("ask_1\n");
            binary_tree(n,ar[x].left_node_no);
        }
    }

    else
    {
        if(ar[x].right_node_no == (-1))
        {
            ar[x].right_node_no =  ar[i].node;
            printf("ar[%d].right_node_no: %d\n",x,ar[x].right_node_no);
        }
        else
        {
//            printf("ask_2\n");
            binary_tree(n,ar[x].right_node_no);
        }
    }
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int j,n;

    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            ar[i].left_node_no = -1;
            ar[i].right_node_no = -1;
        }

        cnt=1;
        scanf("%d",&ar[1].value);
        ar[0].node = cnt++;

        for(i=2;i<=n;i++)
        {
            scanf("%d",&ar[i].value);
            ar[i].node = cnt++;
            printf("ar[%d].value: %d\n",i,ar[i].value);
            printf("ar[%d].node : %d\n",i,ar[i].node);
            binary_tree(ar[i].value,1);
        }

    }

    return 0;
}

