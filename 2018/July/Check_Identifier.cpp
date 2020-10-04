#include <stdio.h>
#include <string.h>

bool identifier(char str[],int len)
{
    int i;
    if((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str[0]=='_')
    {
        for(i=0;i<len;i++)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]=='_' || (str[i]>='0' && str[i]<='9'))
                continue;
            else
                break;
        }
        if(i==len)
            return true;
    }
    return false;
}

int main()
{
    int i,len,cnt;
    char str[110],temp[110];
    gets(str);
    len = strlen(str);
    cnt = 0;
    for(i=0;i<=len;i++)
    {
        if(str[i]==' ' || i==len)
        {
            temp[cnt] = '\0';
            if(identifier(temp,cnt))
                printf("%s -> is a identifier\n",temp);
            else
                printf("%s -> is not a identifier\n",temp);
            cnt = 0;
        }
        else
        {
            temp[cnt] = str[i];
            cnt++;
        }
    }

    return 0;
}
