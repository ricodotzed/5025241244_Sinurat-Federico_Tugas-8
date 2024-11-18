
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[21];
    int unit_cost;
    char category;

    union {
        struct {
            char meat_type;
            char packaging_date[11];
            char expiration_date[11];
        } meat;

        struct {
            char produce_type;
            char date_received[11];
        } produce;

        struct {
            char expiration_date[11];
        } dairy;

        struct {
            char expiration_month_year[7];
            int aisle_number;
            char aisle_side;
        } canned_goods;

        struct {
            char nonfood_type;
            int aisle_number;
            char aisle_side;
        } nonfoods;
    } additional_data;
} product_t;

void input(product_t *product) {
    printf("Enter product name (max 20 characters): ");
    scanf("%20s", product->name);

    printf("Enter unit cost (in cents): ");
    scanf("%d", &product->unit_cost);

    printf("Enter category ('M', 'P', 'D', 'C', 'N'): ");
    scanf(" %c", &product->category);

    switch (product->category) {
        case 'M':
            printf("Enter meat type ('R', 'P', 'F'): ");
            scanf(" %c", &product->additional_data.meat.meat_type);

            printf("Enter packaging date (DD/MM/YYYY): ");
            scanf("%10s", product->additional_data.meat.packaging_date);

            printf("Enter expiration date (DD/MM/YYYY): ");
            scanf("%10s", product->additional_data.meat.expiration_date);
            break;

        case 'P':
            printf("Enter produce type ('F' or 'V'): ");
            scanf(" %c", &product->additional_data.produce.produce_type);

            printf("Enter date received (DD/MM/YYYY): ");
            scanf("%10s", product->additional_data.produce.date_received);
            break;

        case 'D':
            printf("Enter expiration date (DD/MM/YYYY): ");
            scanf("%10s", product->additional_data.dairy.expiration_date);
            break;

        case 'C':
            printf("Enter expiration date (MM/YYYY): ");
            scanf("%6s", product->additional_data.canned_goods.expiration_month_year);

            printf("Enter aisle number: ");
            scanf("%d", &product->additional_data.canned_goods.aisle_number);

            printf("Enter aisle side ('A' or 'B'): ");
            scanf(" %c", &product->additional_data.canned_goods.aisle_side);
            break;

        case 'N':
            printf("Enter nonfood type ('C', 'P', 'O'): ");
            scanf(" %c", &product->additional_data.nonfoods.nonfood_type);

            printf("Enter aisle number: ");
            scanf("%d", &product->additional_data.nonfoods.aisle_number);

            printf("Enter aisle side ('A' or 'B'): ");
            scanf(" %c", &product->additional_data.nonfoods.aisle_side);
            break;

        default: 
            printf("Invalid category.\n");
            break;
    }
}

void output(const product_t *product) {
    printf("Product Name: %s\n", product->name);
    printf("Unit Cost: %d cents\n", product->unit_cost);
    printf("Category: %c\n", product->category);

    switch (product->category) {
        case 'M':
            printf("  Meat Type: %c\n", product->additional_data.meat.meat_type);
            printf("  Packaging Date: %s\n", product->additional_data.meat.packaging_date);
            printf("  Expiration Date: %s\n", product->additional_data.meat.expiration_date);
            break;

        case 'P':
            printf("  Produce Type: %c\n", product->additional_data.produce.produce_type);
            printf("  Date Received: %s\n", product->additional_data.produce.date_received);
            break;

        case 'D':
            printf("  Expiration Date: %s\n", product->additional_data.dairy.expiration_date);
            break;

        case 'C':
            printf("  Expiration Date: %s\n", product->additional_data.canned_goods.expiration_month_year);
            printf("  Aisle Number: %d\n", product->additional_data.canned_goods.aisle_number);
            printf("  Aisle Side: %c\n", product->additional_data.canned_goods.aisle_side);
            break;

        case 'N':
            printf("  Nonfood Type: %c\n", product->additional_data.nonfoods.nonfood_type);
            printf("  Aisle Number: %d\n", product->additional_data.nonfoods.aisle_number);
            printf("  Aisle Side: %c\n", product->additional_data.nonfoods.aisle_side);
            break;

        default:
            printf("Invalid category.\n");
            break;
    }
}

int main() {
    product_t product;
    input(&product);
    printf("\nProduct Information:\n");
    output(&product);
    return 0;
}