#include <stdio.h>
#include <string.h>
#include <math.h>


int Decimal(char nmbr[],int from)
{
    int temp,decimal,i,len;
    len = strlen(nmbr);

    decimal = 0;
    for(i=0;i<len;i++)
    {
        if(nmbr[i] >= 65)
            temp = nmbr[i]-55;
        else
            temp = nmbr[i]-48;

        decimal+=(temp*(pow(from,len-i-1)));
    }

    return decimal;
}


void Target(int decimal,int to,char ar[])
{
    int i=0,x;

    if(decimal == 0)
    {
        ar[0]=48;
        ar[1]='\0';
        return ;
    }

    while(decimal != 0)
    {
        x = decimal % to;
        if(x<10)
            ar[i] = x + 48;
        else
            ar[i] = x + 55;

        decimal/=to;
        i++;
    }
    ar[i]='\0';
}


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char nmbr[10],ar[10],temp[10];
    int decimal,from,to,len,i;

    while(3==scanf("%s%d%d",nmbr,&from,&to))
    {
        decimal = Decimal(nmbr,from);
        Target(decimal,to,ar);
        len = strlen(ar);

        for(i=0;i<len;i++)
            temp[len-i-1] = ar[i];
        temp[len]='\0';

        if(len>7)
            printf("  ERROR\n");
        else
        {
            for(i=0;i<7-len;i++)
                printf(" ");
            printf("%s\n",temp);
        }
    }

    return 0;
}

