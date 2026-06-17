#include <stdio.h>
#include <stdlib.h>
void display_file_with_line_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char line[1024];  // Buffer to store each line
    int line_number = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_number++, line);
    }
     fclose(file);  // Close the file after reading
}
int main() {
    FILE *file = fopen("newfile222.txt", "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(file, "This is the first line.\n");
    fprintf(file, "This is the second line.\n");
    fprintf(file, "This is the third line.\n");
    fclose(file); 
    display_file_with_line_numbers("newfile222.txt");
}

