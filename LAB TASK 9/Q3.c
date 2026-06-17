#include <stdio.h>
#include <string.h>

int main()
{
    char students[1][20] = {"admin"};
    char name[20];
    int pass;
    int found = 0;
    int i ;
    printf("Enter a name: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%d", &pass);

    for (i = 0; i < 1; i++) {
        if (strcmp(students[i], name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        if (pass == 1234) {
            printf("Access Granted\n");
        } else {
            printf("Access Denied: Incorrect password\n");
        }
    } else {
        printf("Access Denied: Username not found\n");
    }

    return 0;
}

