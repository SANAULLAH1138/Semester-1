#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 20
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    int publicationYear;
    int isAvailable;
} Book;

void addBook(Book library[], int *numBooks);
void searchBook(Book library[], int numBooks, const char *searchTerm);
void updateAvailability(Book library[], int numBooks, const char *isbn, int availabilityStatus);
void displayMenu();

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;

            case 2:
                {
                    char searchTerm[MAX_TITLE_LENGTH];
                    printf("Enter title or author to search for: ");
                    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
                    searchTerm[strcspn(searchTerm, "\n")] = '\0';
                    searchBook(library, numBooks, searchTerm);
                }
                break;

            case 3:
                {
                    char isbn[MAX_ISBN_LENGTH];
                    int availabilityStatus;
                    printf("Enter the ISBN of the book: ");
                    fgets(isbn, MAX_ISBN_LENGTH, stdin);
                    isbn[strcspn(isbn, "\n")] = '\0';

                    printf("Enter availability status (1 for Available, 0 for Checked Out): ");
                    scanf("%d", &availabilityStatus);
                    getchar();
                    updateAvailability(library, numBooks, isbn, availabilityStatus);
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nLibrary Database Menu:\n");
    printf("1. Add a new book\n");
    printf("2. Search for a book\n");
    printf("3. Update book availability\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addBook(Book library[], int *numBooks) {
    if (*numBooks < MAX_BOOKS) {
        printf("Enter the title of the book: ");
        fgets(library[*numBooks].title, MAX_TITLE_LENGTH, stdin);
        library[*numBooks].title[strcspn(library[*numBooks].title, "\n")] = '\0';

        printf("Enter the author of the book: ");
        fgets(library[*numBooks].author, MAX_AUTHOR_LENGTH, stdin);
        library[*numBooks].author[strcspn(library[*numBooks].author, "\n")] = '\0';

        printf("Enter the ISBN of the book: ");
        fgets(library[*numBooks].isbn, MAX_ISBN_LENGTH, stdin);
        library[*numBooks].isbn[strcspn(library[*numBooks].isbn, "\n")] = '\0';

        printf("Enter the publication year of the book: ");
        scanf("%d", &library[*numBooks].publicationYear);
        getchar();

        library[*numBooks].isAvailable = 1;
        (*numBooks)++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full, cannot add more books.\n");
    }
}

void searchBook(Book library[], int numBooks, const char *searchTerm) {
    int found = 0;
    printf("Search results:\n");

    for (int i = 0; i < numBooks; i++) {
        if (strstr(library[i].title, searchTerm) != NULL || strstr(library[i].author, searchTerm) != NULL) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %s\n", library[i].isbn);
            printf("Publication Year: %d\n", library[i].publicationYear);
            printf("Availability: %s\n", library[i].isAvailable ? "Available" : "Checked Out");
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching '%s'.\n", searchTerm);
    }
}

void updateAvailability(Book library[], int numBooks, const char *isbn, int availabilityStatus) {
    int found = 0;

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            library[i].isAvailable = availabilityStatus;
            printf("Book with ISBN %s is now %s.\n", isbn, availabilityStatus ? "Available" : "Checked Out");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ISBN %s.\n", isbn);
    }
}

