#include<stdio.h>
#include<string.h>

/*
  A string is said to be a palindrome if the string read from left to right
  is equal to the string read from right to left.
  Ex: ABCDCBA, MADAM.
*/

int main()
{
    int i,len,flag = 1;
    char str[100];

    printf("Enter a string: ");
    scanf("%s",str);

    len = strlen(str);

    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            flag = 0;
            break;
        }
    }

    if(flag==1)
    {
        printf("%s is palindrome\n",str);
    }
    else
    {
        printf("%s is not palindrome\n",str);
    }

    return 0;
}
