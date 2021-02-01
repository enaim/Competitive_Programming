#include<iostream>
using namespace std;

char str[50];
int Len()
{
    int i;
    for(i=0; str[i]!='\0'; i++) {}
    return i;
}
int main()
{
    int t,k,leftpar=0,tmp=0,ans=0,i=0;
    cin>>t;
    while(t--)
    {
        leftpar=tmp=ans=i=0;
        cin>>k>>str;
        while(i<Len())
        {
            if(str[i]=='(')
            {
                leftpar++;
                i++;
            }
            else if(str[i]==')')
            {
                leftpar--;
                i++;
            }
            else
            {
                if(leftpar==k+1)
                {
                    while(str[i]>=48 && str[i]<=57){
                        tmp*=10;
                        tmp+=(str[i]-'0');
                        i++;
                    }
                    ans+=tmp;
                    tmp=0;
                }
                else {
                    i++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
/*
1
2
(0(5(6()())(4()(9()())))(7(1()())(3()())))

*/
