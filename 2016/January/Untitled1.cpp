#include <stdio.h>
#include <string.h>
#include <math.h>



void rmvZero(char a[])
{
    int i,j,len;

    len=strlen(a);
    j=0;

    for(i=0;i<len;i++)
        {
            if(a[i]=='0')
                j++;
            else
                break;
        }
        if(j==len)
        {
            a[0]='0';
            a[1]=0;
        }


        else if(j>0)
        {
            for(i=0;i<len;i++)
            {
                if(j<len)
                {
                    a[i]=a[j];
                    j++;
                }
                else
                    break;
            }
                a[i]=0;
        }
}




int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char a[100];
    while(1==scanf("%s",a))
    {
        printf("%s\n",a);
        rmvZero(a);
        printf("%s\n",a);
    }

    return 0;
}
