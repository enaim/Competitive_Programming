#include <stdio.h>
#include <string.h>
//#include <math.h>


///Return_Type Function_Name(Data_Type1 Paramiter1, Data_Type2 Paramiter2......)

void rev(char ar[])
{
    char temp[100];
    int i,ind,len= strlen(ar);

    ind=len-1;

    for(i=0;i<len;i++)
    {
        temp[i] = ar[ind];
        ind--;
    }
    temp[len] = '\0';

    strcpy(ar,temp);

    printf("ar: %s\n",ar);
}


void printChar(char c)
{
    printf("c : %c\n",c);
    c = 'A';
}

int main()
{
    char in[111];

    scanf("%s",in);

    rev(in);    ///Pass by reference

    printf("in: %s\n",in);


    printChar(in[0]);

    printf("in: %s\n",in);

    return 0;
}
