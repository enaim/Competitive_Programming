#include <stdio.h>
#include <string.h>
//#include <math.h>


///Return_Type Function_Name(Data_Type1 Paramiter1, Data_Type2 Paramiter2......)


double pi()
{
    printf("In the function\n");

    return 3.1416;
}

int pow(int b,int p)
{
    int res=1;

    for(int i=0;i<p;i++)
        res*=b;

        printf("result : %d\n",res);

    return res;

    for(int i=0;i<p;i++)
        res*=b;

        printf("result : %d\n",res);

}



int main()
{
    double r=3,p,ans;

    p = pi();

    ans = pow(r,2)*p;

    printf("ans: %lf\n",ans);

    return 0;
}
