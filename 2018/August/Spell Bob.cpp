#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tks,ks=1,i;
    int ar[3],br[3];
    char s1[10],s2[10];
    scanf("%d",&tks);

    while(tks--)
    {
        ar[0]=ar[1]=ar[2]=br[0]=br[1]=br[2]=0;
        scanf("%s%s",s1,s2);
        for(i=0;i<3;i++)
        {
            if(s1[i]=='b' || s2[i]=='b')
                ar[i]=1;
            if(s1[i]=='o' || s2[i]=='o')
                br[i]=1;
        }
        if(ar[0]==1 && ar[1]==1 && br[2]==1)
            printf("yes\n");
        else if(ar[0]==1 && ar[2]==1 && br[1]==1)
            printf("yes\n");
        else if(ar[1]==1 && ar[2]==1 && br[0]==1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
