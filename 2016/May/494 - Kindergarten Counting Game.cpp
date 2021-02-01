#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char s[200],c;
    int LetterCounter,WordCounter,i,len;

    while(gets(s))
    {
        WordCounter=0;
        LetterCounter=0;
        len = strlen(s);

        for(i=0;i<len;i++)
        {
            c=s[i];
            if(isalpha(c))
                LetterCounter++;
            else
            {
                if(LetterCounter)
                    WordCounter++;
                LetterCounter=0;
            }
        }

        if(LetterCounter)
            WordCounter++;

        printf("%d\n",WordCounter);
    }

    return 0;
}

