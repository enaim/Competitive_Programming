#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char ch=' ';        ///1 Byte = 2^8 = -128 to 127
    char name[100];
    int l,i;

    printf("%c",65);              ///%c = ascii character

    while(scanf("%s",name)==1)
    {
        for(i=0;name[i]>0;i++)
            printf("%d -> %c\n",name[i],name[i]);          /// %d = ascii value

        l = i;

        printf("NULL: %d\n",name[l]);

        printf("%s\n",name);
    }







//    while()
//    {
//        printf("%c %d",ch,ch);
//    }



    return 0;
}
