#include <stdio.h>
#include <string.h>
#include <math.h>


char ar[200];

int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char word[100];
    int i,j,len,cnt,len1;


    while(gets(ar))
    {
        len= strlen(ar);

        j=0;
        cnt = 0;
        for(i=0;i<len;i++)
        {
            if(ar[i] == ' ')
            {
                len1=strlen(word);
                for(j=len1-1;j>=0;j--)
                    printf("%c",word[j]);
                printf(" ");
                j=0;
                word[0]='\0';
            }
            else
            {
                word[j]=ar[i];
                j++;
                word[j]='\0';
            }
        }

        len1=strlen(word);
        for(j=len1-1;j>=0;j--)
            printf("%c",word[j]);
        printf("\n");
    }

    return 0;
}
