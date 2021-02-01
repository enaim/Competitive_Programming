#include <stdio.h>
#include <string.h>
#include <math.h>


bool palenDrom(int a,int b,char c[])
{
    int i;

    for(i=a;i<=b;i++)
        printf("%c",c[i]);
    printf("\n");

    bool flag = true;

    while(a<=b)
    {
        if(c[a]==c[b])
        {
             a++;
             b--;
        }
        else
        {
            flag=false;
            break;
        }
    }


    return flag;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char c[100];
    int a,b;
    bool x;

    while(3==scanf("%s %d%d",c,&a,&b))
    {
        printf("%s\n",c);
        x=palenDrom(a,b,c);

    if(x==true)
        printf("IS PALENDROM\n");
    else
        printf("IS NOT PALENDROM\n");
    }

    return 0;
}



