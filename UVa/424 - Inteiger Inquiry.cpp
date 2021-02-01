#include <stdio.h>
#include <string.h>
#include <math.h>


void inQuiry (char a[],char b[])
{
    int d,i,j,r,x,y,z,lena,lenb,lenc,ind;

    char c[110];

        lena=strlen(a);
        lenb=strlen(b);

        i=0;
        r=0;
        while(0<lena || 0<lenb)
        {
            x = 0;
            y = 0;

            if(lena>0)
                x=a[--lena]-'0';

            if(lenb>0)
                y=b[--lenb]-'0';

            z=x+y+r;
            d=z%10;
            r=z/10;
            c[i]=d+'0';
            i++;
        }

         if(r==1)
            {
                c[i]=r+48;
                c[i+1]=0;
            }
            else
                c[i]=0;

            lenc=strlen(c);
            ind=lenc-1;

        for(i=0;i<lenc;i++)
        {
            a[i] = c[ind];
            ind--;
        }
        a[lenc] = '\0';
}


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
    char a[110],b[110];
    int i,lenb;

    scanf("%s",b);

    lenb=strlen(b);
    for(i=0;i<lenb;i++)
    {
        a[i]=b[i];
    }
    a[lenb]=0;
    rmvZero(a);

    while(1==scanf("%s",b))
    {
        if(b[0]=='0' && b[1]=='\0')
            break;
        inQuiry(a,b);
        rmvZero(a);
    }
    printf("%s\n",a);

    return 0;
}
