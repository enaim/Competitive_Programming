#include<stdio.h>
#include<string.h>


int main()
{
    int i,j,len,cnt;
    char ch;
    char str[100];

    printf("Enter a string : ");
    scanf("%s",str);

    len = strlen(str);

    for(i=0;i<len;i++)
    {
        cnt = 0;
        for(j=i+1;j<len;j++)
        {
            if(str[i]==str[j])
            {
                cnt++;
            }
        }
        if(cnt==0)
        {
            ch = str[i];
            break;
        }
    }
    printf("First not-repeated character in this given string is -> %c\n",ch);

    return 0;
}
