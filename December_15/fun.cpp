#include<stdio.h>
#include<math.h>

double areaRec(int a,int b){

    int area = a*b;
    return area;
}


int main()
{
    int a,b,c;

    printf("%lf\n",areaRec(5,10));


    while(true)
    {
        int kk = scanf("%d%d%d",&a,&b,&c);

        printf("%d\n",kk);

    }

    return 0;
}
