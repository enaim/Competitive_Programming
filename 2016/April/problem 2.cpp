#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    // Declare and initialize variables

    int num =7;
    float amt = 123.45;
    char code = 'A';
    double pi = 3.1415926536;
    long long population_of_india = 1000000000000000000;
    char msg[]="Hi";

    //print the values of variables
    printf("NUM = %d\n",num);
    printf("AMT = %.2f\n",amt);
    printf("CODE = %c\n",code);
    printf("PI = %lf\n",pi);
    printf("POPULATION OF INDIA = %lld\n",population_of_india);
    printf("MASSAGE = %s\n",msg);

    return 0;
}

