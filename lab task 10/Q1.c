#include <stdio.h>
void reverse(char *str, int length) 
{
    if (length < 0)
    return;
    printf("%c", str[length]);
   reverse(str, length - 1);
}

int main() 
{
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int length = 0;
    while (str[length] != '\0' && str[length] != '\n') 
	{
        length++;
    }

    printf("Reversed sentence: ");
    reverse(str, length - 1);
    printf("\n");
    return 0;
}
