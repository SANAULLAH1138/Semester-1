#include<stdio.h>
int main()
{
	char ch ;
	printf("enter any charcter ");
	scanf("%c",&ch); 
	switch (ch)
	{
		
		case 'a':
		printf("vowel letter ",ch);
		break;
		case 'e':
		printf("vowel letter ",ch);
			break;
		case 'i':
		printf("vowel letter ",ch);
			break;
		case 'o':
		printf("vowel letter ",ch);
			break;
		case 'u':
		printf("vowel letter ",ch);
			break;
			default:
				printf("consonant  letter !", ch);
				
				break;
	} 
}
