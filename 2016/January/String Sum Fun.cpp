#include <stdio.h>
#include <string.h>
#include <math.h>


int strSum (char a[],char b[],char c[])
{
    int d,i,j,r,x,y,z,lena,lenb,lenc,ind;
    char temp[100];

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
            temp[i] = c[ind];
            ind--;
        }
        temp[lenc] = '\0';

        strcpy(c,temp);
        j=0;

        for(i=0;i<lenc;i++)
        {
            if(c[i]=='0')
                j++;
            else
                break;
        }

        if(j==lenc)
        {
            c[0]='0';
            c[1]=0;
        }

        else if(j>0)
        {
            for(i=0;i<lenc;i++)
            {
                if(j<lenc)
                {
                    c[i]=c[j];
                    j++;
                }
                else
                    break;
            }
                c[i]=0;
        }

        lenc=strlen(c);
        printf("String Sum : %s\n",c);
    return lenc;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int lenc;
    char a[100],b[100],c[100];

    while(2==scanf("%s%s",a,b))
    {
        printf("a: %s\nb: %s\n",a,b);
        lenc=strSum(a,b,c);
        printf("lenth : %d\n",lenc);
    }
    return 0;
}
