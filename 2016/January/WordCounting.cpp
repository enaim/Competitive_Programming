#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char s[200];
    int cnt,i,j,x,len;

    while (gets(s))
    {
        printf("%s\n",s);
        int letterCounter=0;
        int wordCounter=0;
        len  = strlen(s);

        for (i = 0;i<len;i++)
        {
            char c  = s[i];

            if(s[i] ==' ')
            {
                if(letterCounter > 0 )
                    wordCounter++;
                letterCounter = 0;
            }
//            else if( ('a'<=c && c<='z') || ('A'<=c && c<='Z'))
//            else if( islower(c) || isupper(c))
//            else if( isalpha(c))
            else if( isalnum(c))
            {
                letterCounter++;
            }
        }

        if(letterCounter > 0)
            wordCounter++;


        printf("count: %d\n", wordCounter);
    }
}

