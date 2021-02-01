#include<stdio.h>
#include<string.h>


bool isPrime(int n)
{
    int i;
    for(i=3;i<n;i+=2)
        if(n%i==0)
            return false;

    return true;
}


int main()
{
    int N,x,temp;
    bool a,b;

    while(1==scanf("%d",&N))
    {
        if(N==2)
            printf("%d is prime.\n",N);
        else if(N%2==0)
            printf("%d is not prime.\n",N);
        else
        {
            temp=0;
            a=0;
            b=0;
            temp=N;

            a=isPrime(N);
            x=0;
            while (N != 0)
            {
                x = x * 10;
                x = x + N%10;
                N = N/10;
            }
                if(x != temp)
                    b=isPrime(x);

            if(a==1 && b==1)
                printf("%d is emirp.\n",temp);
            else if(a==1)
                printf("%d is prime.\n",temp);
            else
                printf("%d is not prime.\n",temp);
        }
    }

    return 0;
}

