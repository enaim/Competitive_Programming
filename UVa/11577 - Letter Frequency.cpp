#include <stdio.h>
#include <string.h>
#include <math.h>


int coUnt(char s[] ,int j,int k,int len)
{
    int c,i;

    c=0;
    for(i=0;i<len;i++)
        if(s[i]==j ||s[i]==k)
            c++;

    return c;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,c,j,k,r=1,t,w,x,y,z,mx,len;
    char s[210];
    char v[30];
    int p[30],q[30];

    scanf("%d",&t);
    gets(s);

    while(r<=t)
    {
        gets(s);
        len=strlen(s);

        mx=a=c=0;
        j=65;
        k=97;

        for(j=65;j<=90;j++)
        {
            c=coUnt(s,j,k,len);
            if(c>=mx)
            {
                mx=c;
                q[a]=c;
                p[a]=k;
                a++;
            }
            k++;
        }

        y=0;
        for(x=0;x<a;x++)
        {
            if(q[x] == q[a-1])
            {
                q[y]=p[x];
            y++;
            }
        }

        w=0;
        for(z=0;z<=y-1;z++)
        {
                v[z]=q[w];
                w++;
        }
        v[z]='\0';
        printf("%s\n",v);
        r++;
    }

    return 0;
}

