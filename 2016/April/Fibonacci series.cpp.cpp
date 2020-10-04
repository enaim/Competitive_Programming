#include<stdio.h>


int main()
{
    int count, n, t1=0, t2=1, display=0;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    printf("Fibonacci Series: %d+%d+", t1, t2); /* Displaying first two terms */
    count=2; /* count=2 because first two terms are already displayed. */

    while (count<n)
    {
        display=t1+t2;
        t1=t2;
        t2=display;
        ++count;
        printf("%d+",display);
    }

    return 0;
}

