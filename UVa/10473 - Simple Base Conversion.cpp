#include <stdio.h>
#include <string.h>
#include <math.h>


int Decimal(char nmbr[])
{
    int len,decimal=0,i,x;
    char temp[10];

    len = strlen(nmbr);
    for(i=0;i<len-2;i++)
        temp[i]=nmbr[i+2];
    temp[i]='\0';

    len = strlen(temp);
    for(i=0;i<len;i++)
    {
        if(temp[i] >= 65)
            x = temp[i] - 55;
        else
            x = temp[i] - 48;
        decimal+=(x*pow(16,len-i-1));
    }

    return decimal;
}


void HexaDecimal(char nmbr[],char ans[])
{
    char temp[12];
    int len,rev,i,x;

    len = strlen(nmbr);
    rev=0;
    for(i=0;i<len;i++)
        rev = rev * 10 + (nmbr[i]-48);

    if(rev == 0)
    {
        ans[0]=48;
        ans[1]='\0';
        return ;
    }

    i=0;
    while(rev!=0)
    {
        x=rev%16;
        rev/=16;

        if(x>9)
            temp[i]=x+55;
        else
            temp[i]=x+48;
        i++;
    }
    temp[i]='\0';

    len=strlen(temp);
    for(i=0;i<len;i++)
            ans[len-i-1] = temp[i];
        ans[len]='\0';
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char nmbr[12];
    char ans[12];
    char c;
    int decimal;

    while(1==scanf("%s",nmbr) && (nmbr[0] != '-'))
    {
        c = nmbr[1];
        if(c == 'x')
            decimal = Decimal(nmbr);
        else
            HexaDecimal(nmbr,ans);

        if(c == 'x')
            printf("%d\n",decimal);
        else
            printf("0x%s\n",ans);
    }

    return 0;
}

