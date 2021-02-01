#include <stdio.h>
#include <string.h>
#include <math.h>


bool palenDrom(int a,int b,char r[])
{
    int i,j,h,t,v,cnt;
    int f= strlen(r);
    int la=b-a+1;


    printf("f: %d\n",f);
    printf("Length: %d\n",la);

    cnt = 0;
    v=a+b;

    if(v%2==0)
        h=v/2;

    else
        h=(v+1)/2;

    for(i=a;i<h;i++)
    {
        int rit = f-i-1;
            printf("i:%d  rit:%d\n",i,rit);

        if(r[i] == r[rit])
            cnt++;

        else
            break;
    }
        t=la/2;

        printf("\t%d # %d\n",cnt,t);

        if(cnt == t)
            return true;

        else
            return false;
        printf("\tHERE\n");

    return false;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char r[100];
    int a,b,x;

    while(3==scanf("%s%d%d",r,&a,&b))
    {
        printf("%s\n",r);
        x=palenDrom(a,b,r);

    if(x==1)
        printf("IS PALENDROM\n");
    else
        printf("IS NOT PALENDROM\n");
    }

    return 0;
}

