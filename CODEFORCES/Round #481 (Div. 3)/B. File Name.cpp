#include<bits/stdc++.h>
using namespace std;


int main()
{
    int sum = 0;
    int len,i,cnt=0;
    char str[100010];
    scanf("%d%s",&len,str);

    for(i=0;i<len;i++)
    {
        if(str[i]=='x')
            cnt++;
        else
        {
            if(cnt>2)
                sum+= (cnt-2);
            cnt = 0;
        }
    }
    if(cnt>2)
        sum+= (cnt-2);
    cout<<sum<<endl;

    return 0;
}
