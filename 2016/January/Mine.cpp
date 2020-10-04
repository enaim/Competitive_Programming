#include <stdio.h>
#include <string.h>
#include <math.h>


    ///Down, Left, Right, Up
//int dr[]={1, 0,  0, -1;
//int dc[]={0, -1, 1,  0};


//int dr[]={1, 1,  -1, -1, -2, 2, -2,  2;
//int dc[]={-2, 2, -2,  2, 1, 1,  -1, -1};

int friends(int r,int c)
{
    int friendRow,friendColumn;

    for(int i=0;i<4;i++)
    {
        friendRow = r + dr[i];
        friendColumn = c + dc[i];
    }

}

int main()
{
    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,m,n,r,o,p,x=1;
    char c[110][110];

    while(2==scanf("%d%d",&m,&n))
    {
        if(x>1)
            printf("\n");

        if(m==0 && n==0)
            break;
        else
        {
            for(i=0;i<m;i++)
                scanf("%s",c[i]);

            for(i=0;i<m;i++)
                for(j=0;j<n;j++)
                {
                    if(c[i][j]=='.')
                    {
                        r=0;
                        for(o=i-1;o<i+2;o++)
                        {
//                            printf("o: %d\n",o);
                            for(p=j-1;p<j+2;p++)
                            {
//                                printf("p: %d\n",p);
                                if(o>=0 && p>=0 && o<n && p<n)
                                    if(c[o][p]=='*')
                                        r++;
//                                printf("r: %d\n",r);
                            }
                        }
                        c[i][j]=r+48;
                    }
                }

            printf("Field #%d:\n",x++);
            for(i=0;i<m;i++)
                printf("%s\n",c[i]);
//            printf("\n");
        }
    }

    return 0;
}
