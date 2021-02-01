#include <stdio.h>
#include <string.h>
#include <math.h>


int dr[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dc[]={-1, 0, 1,-1, 1,-1, 0, 1};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int r,c,i,j,l,x,y,z,cnt;
    char s[110][110];
    while(2==scanf("%d%d",&r,&c) && (r || c))
    {
        cnt=0;
        for(i=0;i<r;i++)
            scanf("%s",s[i]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                z=0;
                if(s[i][j]=='*')
                {
                    for(l=0;l<8;l++)
                    {
                        x = i + dr[l];
                        y = j + dc[l];
                        if(x < r && x>=0 && y <c && y>=0)
                        {
                            if(s[x][y]=='*')
                                z=1;
                        }
                    }
                    if(z==0)
                        cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
