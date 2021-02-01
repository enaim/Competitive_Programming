#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    map<char,char>mp;
    mp['='] = '-';
    mp['-'] = '0';
    mp['0'] = '9';
    mp['9'] = '8';
    mp['8'] = '7';
    mp['7'] = '6';
    mp['6'] = '5';
    mp['5'] = '4';
    mp['4'] = '3';
    mp['3'] = '2';
    mp['2'] = '1';
    mp['1'] = '`';
    mp[92] = ']';
    mp[']'] = '[';
    mp['['] = 'P';
    mp['P'] = 'O';
    mp['O'] = 'I';
    mp['I'] = 'U';
    mp['U'] = 'Y';
    mp['Y'] = 'T';
    mp['T'] = 'R';
    mp['R'] = 'E';
    mp['E'] = 'W';
    mp['W'] = 'Q';
    mp[39] = ';';
    mp[';'] = 'L';
    mp['L'] = 'K';
    mp['K'] = 'J';
    mp['J'] = 'H';
    mp['H'] = 'G';
    mp['G'] = 'F';
    mp['F'] = 'D';
    mp['D'] = 'S';
    mp['S'] = 'A';
    mp['/'] = '.';
    mp['.'] = ',';
    mp[','] = 'M';
    mp['M'] = 'N';
    mp['N'] = 'B';
    mp['B'] = 'V';
    mp['V'] = 'C';
    mp['C'] = 'X';
    mp['X'] = 'Z';

    char str[100010];
    int len;
    while(gets(str))
    {
        len = strlen(str);
        for(int i =0;i<len;i++)
        {
            if(mp[str[i]] != 0)
                printf("%c",mp[str[i]]);
            else
                printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}


