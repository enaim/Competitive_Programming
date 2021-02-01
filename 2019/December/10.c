#include<stdio.h>
#include<string.h>

int isPalindrome(char str[])
{
    int i,len;
    len = strlen(str);
    for(i=0;i<len/2;i++)
    {
        if(str[i]==str[len-i-1])
            continue;
        else
            break;
    }
    if(i==len/2)
        return 1;
    return 0;
}

int main()
{
    char str[100];

    scanf("%s",str);

    if(isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}
