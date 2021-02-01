#include <stdio.h>
#include <string.h>
#include <math.h>


int dr[] = {-2,-2,-1,-1, 1,1, 2,2};
int dc[] = {-1, 1,-2, 2,-2,2,-1,1};

const int SIZE = 10;
bool flag[SIZE][SIZE];
int distance[SIZE][SIZE];

struct Vartex
{
    int row;
    int column;
};

Vartex Queue[SIZE];
Vartex x,y;

Vartex convert(char n[])
{
    Vartex temp;
    temp.row=n[0]-'a';
    temp.column=n[1]-'1';

    return temp;
}

int adjacent(Vartex r)
{
    Vartex h;
    Vartex Queue[100];
    int i;
    int Front,Rare;

    Front=Rare=0;

    flag[r.row][r.column]=false;
    distance[r.row][r.column]=0;
    Queue[Rare++]=r;

    while(Front < Rare)
    {
        r=Queue[Front++];

        for(i=0;i<8;i++)
        {
            if(r.row<0 || r.column<0 || r.row>=8 || r.column>=8)
                    continue;

            h.row = r.row + dr[i];
            h.column = r.column + dc[i];

            if(flag[h.row][h.column] == false)
                continue;

            flag[h.row][h.column] = false;
            distance[h.row][h.column] = distance[r.row][r.column] + 1;
            Queue[Rare++]= h;

            if(y.row == h.row && y.column == h.column)
                return distance[h.row][h.column];
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char a[10];
    char b[10];

    int i,j,cnt;

    while(2==scanf("%s%s",a,b))
    {
        if(a[0] == b[0] && a[1] == b[1])
            cnt=0;
        else
        {
            memset(flag,true,sizeof flag);

            x = convert(a);
            y = convert(b);

            cnt = adjacent(x);
        }

        printf("To get from %s to %s takes %d knight moves.\n",a,b,cnt);
    }

    return 0;
}
