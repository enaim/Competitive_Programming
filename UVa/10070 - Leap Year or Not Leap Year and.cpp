#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[1000000];
    int mod4,mod15,mod55,mod100,mod400;
    int i,x,len,ks=1;
    while(scanf("%s",str)==1)
    {
        if(ks!=1)
            printf("\n");
        ks++;
        x = 0;
        int len = strlen(str);
        mod4=mod15=mod55=mod100=mod400=0;
        for(i=0;i<len;i++)
        {
            mod4 = (mod4*10 + str[i]-'0')%4;
            mod15 = (mod15*10 + str[i]-'0')%15;
            mod55 = (mod55*10 + str[i]-'0')%55;
            mod100 = (mod100*10 + str[i]-'0')%100;
            mod400 = (mod400*10 + str[i]-'0')%400;
        }
        if(mod4 == 0 && (mod400 == 0 || mod100 != 0))
            printf("This is leap year.\n");
        if(mod15 == 0)
            printf("This is huluculu festival year.\n");
        if((mod4 == 0 && (mod400 == 0 || mod100 != 0)) && mod55 == 0)
        {
            printf("This is bulukulu festival year.\n");
            x= 1;
        }
        if(!(mod4 == 0 && (mod400 == 0 || mod100 != 0)) && mod15!=0)
            printf("This is an ordinary year.\n");
    }

    return 0;
}
