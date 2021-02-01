
double area(int a,int b,int c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

struct node{
    int ind;
    double val;
};

struct node ar[110];
struct triangle temp;


void sort_by_area(triangle* tr, int n) {
    for(int i=0;i<n;i++)
    {
        ar[i].ind = i;
        ar[i].val = area(tr[i].a,tr[i].b,tr[i].c);
    }
    int i,j,ind;
    double mn;
    for(i=0;i<n;i++)
    {
        ind = i;
        mn = ar[i].val;
        for(j=i+1;j<n;j++)
        {
            if(ar[j].val<mn)
            {
                mn = ar[j].val;
                ind = j;
            }
        }
        temp = tr[i];
        tr[i]=tr[ind];
        tr[ind]=temp;
        mn = ar[i].val;
        ar[i].val=ar[ind].val;
        ar[ind].val=mn;
    }
}
