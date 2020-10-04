#include<stdio.h>

#include<math.h>


int main()
{
    double root;

    root = sqrt(2);
    printf("root: %.2lf\n",root);
    printf("root: %.10lf\n",root);

    double power;

    power = pow(3.4,3);
    printf("power: %lf\n",power);

    double val;

    double pi = 3.1415;
    printf("SIN(90) = %lf\n",sin(pi/2));
    printf("SIN Inverse = %lf\n",asin(1));
    printf("SIN Inverse = %lf\n",asin(sin(pi/2)));
}
