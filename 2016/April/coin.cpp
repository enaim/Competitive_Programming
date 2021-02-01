#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    float n,b;
    int a;
    while(1==scanf("%f",&n))
    {
        printf("NOTAS:\n");

        a = n / 100;
        printf("%d nota(s) de R$ 100.00\n",a);

        n = n - (a*100);
        a = n / 50;
        printf("%d nota(s) de R$ 50.00\n",a);

        n = n - (a*50);
        a = n / 20;
        printf("%d nota(s) de R$ 20.00\n",a);

        n = n - (a*20);
        a = n / 10;
        printf("%d nota(s) de R$ 10.00\n",a);

        n = n - (a*10);
        a = n / 5;
        printf("%d nota(s) de R$ 5.00\n",a);

        n = n - (a*5);
        a = n / 2;
        printf("%d nota(s) de R$ 2.00\n",a);

        printf("MOEDAS:\n");

        n = n - (a*2);
        a = n / 1;
        printf("%d moeda(s) de R$ 1.00\n",a);

        n = n - (a*1);
        a = n /.5;
        printf("%d moeda(s) de R$ 0.50\n",a);

        n = n - (a*.5);
        a = n /.25;
        printf("%d moeda(s) de R$ 0.25\n",a);

        n = n - (a*.25);
        a = n /.1;
        printf("%d moeda(s) de R$ 0.10\n",a);

        n = n - (a*.1);
        a = n /.05;
        printf("%d moeda(s) de R$ 0.05\n",a);

        n = n - (a*.05);
        a = n /.01;
        n = n - (a*.01);

        if( n > 0.001)
        {
            printf("%d moeda(s) de R$ 0.01\n",a+1);
        }
        else
        {
            printf("%d moeda(s) de R$ 0.01\n",a);
        }
    }

    return 0;
}

