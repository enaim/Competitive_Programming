using namespace std;

int ar[200010];

int main() {
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,m;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
            scanf("%d",&ar[i]);
        for(j=0;j<n;j++)
            scanf("%d",&ar[m+j]);
        sort(&ar[0],&ar[m+n]);
        for(i=0;i<m+n;i++)
        {
            if(i==0)
                printf("%d",ar[i]);
            else
                printf(" %d",ar[i]);
        }
        printf("\n");
    }

	return 0;
}
