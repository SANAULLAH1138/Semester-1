#include<stdio.h>
int main()
{
    int limit[12], count = 0, n;
    printf("ENTER THE LIMIT (up to 12 elements): ");
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)
    {
        printf("ENTER limit[%d] = ", i + 1);
        scanf("%d", &limit[i]);
    }
    
    int key;
    printf("ENTER THE NUMBER TO SEARCH: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
    {
        if (key == limit[i])
        {
            count++;
            printf("FINDING ELEMENT AT INDEX %d\n", i + 1);        
		}
    }

    if (count == 0)
        printf("ELEMENT NOT FOUND\n");
    
    return 0;
}

