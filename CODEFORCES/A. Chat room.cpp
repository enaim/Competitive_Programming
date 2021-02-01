#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char word[100];
    char hello[] = "hello";
    int i,j,len,cnt;


    while(1 == scanf("%s",word))
    {
        len= strlen(word);

        j=0;
        cnt = 0;
        for(i=0;i<len;i++)
        {
            if(word[i] == hello[j])
            {
                cnt++;
                j++;
            }
        }

        if(cnt == 5)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
