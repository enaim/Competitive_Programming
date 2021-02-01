#include <stdio.h>
#include <string.h>


int main()
{
	int i,j,n;
	char str[100][100],temp[100];

	printf("Number of Names : ");
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%s",str[i]);

		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(str[j],str[j+1]) > 0)
				{
					strcpy(temp,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],temp);
				}
			}	

		printf("\n\nAfter Sorting");
		for(i=0;i<n;i++)
			printf("%s\n",str[i]);
	}
}