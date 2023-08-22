#include <stdio.h>
#include <stdlib.h>

typedef struct Wallet {
    int mainBalance;
    int miniBalance;
    int savingsBalance;
} Wallet;

void allocateSavings(Wallet *wallet) {
    int allocateAmount;
    printf("Enter amount to allocate for savings: ");
    scanf("%d", &allocateAmount);
    if (allocateAmount <= wallet->mainBalance) {
        wallet->mainBalance -= allocateAmount;
        wallet->savingsBalance += allocateAmount;
        printf("Amount allocated for savings successfully.\n");
    } else {
        printf("Insufficient balance for allocation.\n");
    }
}

int main(void) {
    Wallet *wallet = malloc(sizeof(Wallet));
    if (wallet == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    wallet->mainBalance = 0;
    wallet->miniBalance = 0;
    wallet->savingsBalance = 0;

    int income, expenses, transferAmount;
    char choice;

    putchar('\n');
    printf("Welcome to the BOSSU SUSU App!\n");

    do {
        printf("\nMain Balance: %d\n", wallet->mainBalance);
        printf("Mini Wallet Balance: %d\n", wallet->miniBalance);
        printf("Savings Balance: %d\n", wallet->savingsBalance);
        printf("1. Add Income\n");
        printf("2. Add Expenses\n");
        printf("3. Allocate for Savings\n");
        printf("4. Transfer to Mini Wallet\n");
        printf("5. Transfer from Mini Wallet\n");
        printf("6. Exit\n");
        putchar('\n');
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter income amount: ");
                scanf("%d", &income);
                wallet->mainBalance += income;
                break;

            case '2':
                printf("Enter expenses amount: ");
                scanf("%d", &expenses);
                wallet->mainBalance -= expenses;
                break;

            case '3':
                allocateSavings(wallet);
                break;

            case '4':
                printf("Enter amount to transfer to Mini Wallet: ");
                scanf("%d", &transferAmount);
                if (transferAmount <= wallet->mainBalance) {
                    wallet->mainBalance -= transferAmount;
                    wallet->miniBalance += transferAmount;
                } else {
                    printf("Insufficient balance in main account.\n");
                }
                break;

            case '5':
                printf("Enter amount to transfer from Mini Wallet: ");
                scanf("%d", &transferAmount);
                if (transferAmount <= wallet->miniBalance) {
                    wallet->miniBalance -= transferAmount;
                    wallet->mainBalance += transferAmount;
                } else {
                    printf("Insufficient balance in Mini Wallet.\n");
                }
                break;

            case '6':
                printf("Exiting the BOSSU SUSU App.\n");
                 putchar('\n');
                break;

            default:
                putchar('\n');
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != '6');

    free(wallet);
    return 0;
}

