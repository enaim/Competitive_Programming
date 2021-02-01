#include <stdio.h>
#include <string.h>


int main()
{
	int i,j,k,len1,len2,flag;
	char str[100],sbstr[100];

	while(scanf("%s%s",str,sbstr)==2)
	{
		len1 = strlen(str);
		len2 = strlen(sbstr);

		flag = 0;
		for(i=0;i<len1-len2+1;i++)
		{
			if(str[i] == sbstr[0])
			{
				j = i+1;
				k = 1;
				while(str[j] == sbstr[k])
				{
					j++;
					k++;
					if(k == len2)
					{
						flag = 1;
						printf("Pattern Matching from position %d to %d\n",i+1,i+len2);
					}
				}
			}
		}
		if(flag == 0)
			printf("Pattern doesn't Matched.\n");
	}

	return 0;
}