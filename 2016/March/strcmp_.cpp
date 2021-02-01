#include<stdio.h>
#include<string.h>

int main()
{
    printf("%d\n",strcmp("AA","AA"));       ///( s1[i] = s2[i] ) { return  0; }
    printf("%d\n",strcmp("AA","AB"));
    printf("%d\n",strcmp("AA","AC"));       ///( s1[i] < s2[i] ) { return -1; }
    printf("%d\n",strcmp("AC","AA"));
    printf("%d\n\n",strcmp("AD","AA"));     ///( s1[i] > s2[i] ) { return  1; }


    printf("%d\n",strcmp("A","AA"));
    printf("%d\n",strcmp("B","AA"));
}
