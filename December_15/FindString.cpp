#include<stdio.h>
#include<string.h>


int findStr(char txt[],char pat[])
{
    int i,j;
    int lt = strlen(txt);
    int lp = strlen(pat);
    int cnt;

    for(i=0;i<lt-lp+1;i++)
    {
        cnt=0;

        for(j=0;j<lp;j++)
            if(txt[i+j]==pat[j])
            {
                cnt++;
            }
            else break;

        if(cnt==lp) return i;
    }


    return -1;
}

int main()
{
    char  a[100],b[10];
    int ind;

    while(2==scanf("%s%s",a,b))
    {
        printf("%s %s\n",a,b);
        ind=findStr(a,b);

        printf("Index Number : %d\n",ind);
    }

    return 0;
}

