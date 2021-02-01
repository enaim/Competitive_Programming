#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tks,ks=1;
    int d,m;

    while(scanf("%d%d",&d,&m)==2)
    {
        if(d==7 && m==1)
            printf("Happy Birthday To Shipu.\n");
       else if(d==29 && m==4)
            printf("Happy Birthday To Dipu Sir.\n");
        else if(d==30 && m==5)
            printf("Happy Birthday To Fahad vai.\n");
        else if(d==21 && m==6)
            printf("Happy Birthday To Sufian.\n");
        else if(d==11 && m==12)
            printf("Happy Birthday To Alim.\n");
        else
            printf("This is an ordinary day.\n");
    }

    return 0;
}
