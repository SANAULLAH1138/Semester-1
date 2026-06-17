#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "books.txt"
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int quantity;
    float price;
};

// Function to add a new book to the library
void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);

    // Check for duplicate book ID
    struct Book existingBook;
    FILE *readFile = fopen(FILENAME, "r");
    if (readFile != NULL) {
        while (fread(&existingBook, sizeof(struct Book), 1, readFile)) {
            if (existingBook.id == newBook.id) {
                printf("Book with ID %d already exists.\n", newBook.id);
                fclose(readFile);
                fclose(file);
                return;
            }
        }
        fclose(readFile);
    }

    getchar();  // To consume the newline left by scanf

    printf("Enter Book Title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    if (newBook.quantity < 0) {
        printf("Quantity cannot be negative. Setting quantity to 0.\n");
        newBook.quantity = 0;
    }

    printf("Enter Price: ");
    scanf("%f", &newBook.price);
    if (newBook.price < 0) {
        printf("Price cannot be negative. Setting price to 0.0.\n");
        newBook.price = 0.0;
    }

    fwrite(&newBook, sizeof(struct Book), 1, file);
    fclose(file);

    printf("Book added successfully.\n");
}

// Function to view all books in the library
void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    printf("\n--- Book Records ---\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("ID: %d\n", book.id);
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Quantity: %d\n", book.quantity);
        printf("Price: %.2f\n", book.price);
        printf("-----------------------\n");
    }

    fclose(file);
}

// Function to search for a book by ID or title
void searchBook() {
    int choice;
    printf("Search by:\n1. Book ID\n2. Book Title\nEnter your choice: ");
    scanf("%d", &choice);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Book ID to search: ");
        scanf("%d", &id);

        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (book.id == id) {
                printf("Book found:\n");
                printf("ID: %d\n", book.id);
                printf("Title: %s\n", book.title);
                printf("Author: %s\n", book.author);
                printf("Quantity: %d\n", book.quantity);
                printf("Price: %.2f\n", book.price);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        getchar();  // To consume newline character
        char title[MAX_TITLE_LENGTH];
        printf("Enter Book Title to search: ");
        fgets(title, MAX_TITLE_LENGTH, stdin);
        title[strcspn(title, "\n")] = '\0';

        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (strstr(book.title, title)) {
                printf("Book found:\n");
                printf("ID: %d\n", book.id);
                printf("Title: %s\n", book.title);
                printf("Author: %s\n", book.author);
                printf("Quantity: %d\n", book.quantity);
                printf("Price: %.2f\n", book.price);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No matching books found.\n");
    }

    fclose(file);
}

// Function to update book details
void updateBook() {
    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "r+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &book.quantity);
            if (book.quantity < 0) {
                printf("Quantity cannot be negative. Setting quantity to 0.\n");
                book.quantity = 0;
            }

            printf("Enter new price: ");
            scanf("%f", &book.price);
            if (book.price < 0) {
                printf("Price cannot be negative. Setting price to 0.0.\n");
                book.price = 0.0;
            }

            fseek(file, -sizeof(struct Book), SEEK_CUR);  // Move pointer back to overwrite record
            fwrite(&book, sizeof(struct Book), 1, file);
            printf("Book updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }

    fclose(file);
}

// Function to delete a book
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    struct Book book;
    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1;
            printf("Book with ID %d deleted.\n", id);
        } else {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    } else {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
    }
}

// Function to calculate the total inventory value
void calculateInventoryValue() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    float totalValue = 0.0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        totalValue += book.quantity * book.price;
    }

    printf("Total inventory value: %.2f\n", totalValue);
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Calculate Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                calculateInventoryValue();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

