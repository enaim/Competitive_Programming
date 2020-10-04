#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char s[100],l;

    char ch=97;
    printf("%d -> %c\n",ch,ch);

    l=0;
    for(int i=0;i<10;i++)
        s[l++] = i+'0';

    s[l]='\0';


    printf("Stirng: %s\n",s);

    return 0;
}
