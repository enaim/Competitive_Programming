#include<stdio.h>
#include<string.h>


int findStr(char txt[],char pat[])
{
    int t,i,j;
    int lt = strlen(txt);
    int lp = strlen(pat);
    int cnt;

    for(i=0;i<lt-lp+1;i++)
    {
        cnt=0;

        for(j=0;j<lp;j++)
            if( txt[i+j]==pat[j] )
            {
                cnt++;
            }
            else break;

        if(cnt==lp)
        {
            t=lp+i-1;
            return t;
        }
    }


    return -1;
}

int main()
{
    char  a[100],b[10];
    int ind;

    while(2==scanf("%s%s",a,b))
    {
        printf("%s %s",a,b);
        ind=findStr(a,b);

        printf("\nIndex Number : %d\n",ind);
    }

    return 0;
}


