#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char ch;
    char name[100],word[100];
    int l,i;

    while(scanf("%s",name)==1)
    {
        strcpy(word,name);               ///strcpy = string copy
        strcpy(name,"maksud");
//        strcpy(name,'maksud');  ///wrong
//        strcpy(name,maksud);  ///wrong

        printf("name: %s\nword: %s\n",name,word);
    }







//    while()
//    {
//        printf("%c %d",ch,ch);
//    }



    return 0;
}
