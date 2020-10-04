#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

struct Coordinate{
    int x;
    int y;
};

Coordinate coordinate[50];

bool compare(Coordinate a,Coordinate b)
{
    if(a.x > b.x)
        return true;
    if(a.x== b.x && a.y > b.y)
        return true;

    return false;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&coordinate[i].x);
            scanf("%d",&coordinate[i].y);
        }
        for(i=0;i<n;i++)
            for(j=0;j<n-1-i;j++)
            {
                if(compare(coordinate[j],coordinate[j+1]))
                {
                    Coordinate temp = coordinate[j];
                    coordinate[j] = coordinate[j+1];
                    coordinate[j+1] = temp;
                }
            }

        for(i=0;i<n;i++)
        {
            printf("X : %d  Y : %d\n",coordinate[i].x,coordinate[i].y);
            printf("\n");
        }
    }
}
