#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char ar[1000];
    int len,i,cnt=0;

    while(gets(ar))
    {
        len = strlen(ar);

        for(i=0;i<len;i++)
        {
            if(ar[i] == '"')
            {
                cnt++;

                if(cnt%2==1)
                    printf("``");
                else
                    printf("''");
            }
            else
                printf("%c",ar[i]);
        }
        printf("\n");
    }

    return 0;
}

