#include <stdio.h>
#include <string.h>



int convert_to_integer(char str[])
{
	int x = 0,i,len;
	len = strlen(str);

	for(i=0;i<len-1;i++)
	{
		x = x*10 + (str[i]-'0');
	}

	return x;
}



int main()
{

	int a,b,c,d,n=1;
	char sign1[2],sign2[2];
	char imaginary1[20],imaginary2[20];

	while(n)
	{
		printf("First Complex Number in (x + yi) Format : ");
		scanf("%d%s%s",&a,sign1,imaginary1);

		printf("Second Complex Number in (x + yi) Format : ");
		scanf("%d%s%s",&c,sign2,imaginary2);
		
		b = convert_to_integer(imaginary1);
		d = convert_to_integer(imaginary2);


		printf("Answer : ");
		if(sign1[0] == '+' && sign2[0] == '+')		//a + bi & c + di
			printf("%d + %di\n",a+c,b+d);

		else if(sign1[0] == '-' && sign2[0] == '-')		//a - bi & c - di
			printf("%d - %di\n",a+c,b+d);

		else if(sign1[0] == '+' && sign2[0] == '-')		//a + bi & c - di
		{
			if(b>d)
				printf("%d + %di\n",a+c,b-d);
			else
				printf("%d - %di\n",a+c,d-b);
		}

		else											//a - bi & c + di
		{
			if(b>d)
				printf("%d - %di\n",a+c,b-d);
			else
				printf("%d + %di\n",a+c,d-b);	
		}
			printf("Press One to Continue or Zero to Exit.\n");
			scanf("%d",&n);

	}

	return 0;
}
