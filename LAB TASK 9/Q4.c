#include <stdio.h>
#include <string.h>
int main()
{
    char students[5][20] = {"HASSAN", "ABDUL", "HASNAIN", "ALI", "AHMED"};
    char name[20];
    int found = 0;
    int i ;
    printf("Enter a name: ");
    scanf("%s", name);

    for ( i = 0; i < 5; i++) {
        if (strcmp(students[i], name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

