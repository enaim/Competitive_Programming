#include <stdio.h>
#include <string.h>

int Prefix[100];
char Pattern[100];

void Compute_Prefix_Function()
{
    int k,q,m;
    m = strlen(Pattern);
    Prefix[0]=0;
    k = 0;

    for(q=1;q<m;q++)
    {
        while((k>0) && (Pattern[k] != Pattern[q]))
            k = Prefix[k];
        if(Pattern[k] == Pattern[q])
            k = k + 1;
        Prefix[q]=k;
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char Text[100];
    int m,n,i,q;

    while(2==scanf("%s%s",Text,Pattern))
    {
        n = strlen(Text);
        m = strlen(Pattern);
        Compute_Prefix_Function();

        q = 0;
        for(i=0;i<n;i++)
        {
            while((q>0) && (Pattern[q] != Text[i]))
                q = Prefix[q-1];

            if(Pattern[q]==Text[i])
            {
                q = q+1;

                if(q==m)
                    printf("Pattern occurs with shift %d\n",i-m);
            }
            else
                q = Prefix[q];
        }
    }

    return 0;
}
