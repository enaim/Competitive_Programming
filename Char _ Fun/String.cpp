#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char ch;
    char name[100];
    int l,i,stringLength;

    while(scanf("%s",name)==1)
    {
        for(i=0;name[i]>0;i++)
            printf("%d -> %c\n",name[i],name[i]);

        l = i;

        printf("NULL: %d\n",name[l]);

        printf("%s # %d\n",name,l);

        stringLength =  strlen(name);           //strlen(array's name) means the length of string

        printf("Length Of the String: %d\n",stringLength);
        printf("Length Of the String: %d\n",strlen(name));
    }







//    while()
//    {
//        printf("%c %d",ch,ch);
//    }



    return 0;
}
