#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,m,n,r,o,p,x=1;
    char c[110][110];

    while(2==scanf("%d%d",&m,&n))
    {
        if(m==0 && n==0)
            break;
        else
        {
            for(i=0;i<m;i++)
                scanf("%s",c[i]);

            if(x>1)
                printf("\n");

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
                                if(o>=0 && p>=0 && o<m && p<n)
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
