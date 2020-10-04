#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char n[210],v[26];
    int z[26];

    int i,j,x,w,t,r=1,len,mx;
    scanf("%d",&t);
    gets(n);
    while(r<=t)
    {
        gets(n);
        len=strlen(n);
        for(j=0;j<26;j++)
          z[j]=0;

        for(i=0;n[i]>0;i++)
        {
            if(n[i]>64 && n[i]<91)
                n[i]+=32;
        }

        j=0;
        for(i=0;i<len;i++)
        {
            x=n[i];

            if(n[i]>=97 && n[i]<=122)
            {
                j=x-97;
                z[j]+=1;
            }

        }
        mx=0;
        for(i=1;i<26;i++)
        {
            if(z[i]>z[mx])
                mx=i;
        }
        w=0;
        for(i=0;i<26;i++)
        {
            if(z[i]==z[mx])
            {
                v[w]=i+97;
                w++;
            }
        }

        v[w]='\0';
        printf("%s\n",v);
        r++;
    }

    return 0;

}

