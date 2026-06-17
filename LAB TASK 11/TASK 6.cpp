#include <stdio.h>
#include <string.h>

struct Invoice {
    char part_number[50];
    char part_description[100];
    int quantity;
    float price_per_item;
};

void initializeInvoice(struct Invoice* invoice, const char* part_number, const char* part_description, int quantity, float price_per_item) {
    strcpy(invoice->part_number, part_number);
    strcpy(invoice->part_description, part_description);
    invoice->quantity = (quantity > 0) ? quantity : 0;
    invoice->price_per_item = (price_per_item > 0) ? price_per_item : 0.0;
}

float calculateInvoiceAmount(struct Invoice invoice) {
    return invoice.quantity * invoice.price_per_item;
}

int main() {
    struct Invoice invoice;

    char part_number[50];
    char part_description[100];
    int quantity;
    float price_per_item;

    printf("Enter part number: ");
    fgets(part_number, sizeof(part_number), stdin);
    part_number[strcspn(part_number, "\n")] = '\0';

    printf("Enter part description: ");
    fgets(part_description, sizeof(part_description), stdin);
    part_description[strcspn(part_description, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price_per_item);

    initializeInvoice(&invoice, part_number, part_description, quantity, price_per_item);

    printf("\nInvoice Details:\n");
    printf("Part Number: %s\n", invoice.part_number);
    printf("Part Description: %s\n", invoice.part_description);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price Per Item: %.2f\n", invoice.price_per_item);
    printf("Invoice Amount: %.2f\n", calculateInvoiceAmount(invoice));

    return 0;
}

