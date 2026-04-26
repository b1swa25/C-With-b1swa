#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "accounts.dat"
#define ADMIN_PASSWORD "admin123"

typedef struct {
    int account_no;
    char name[100];
    double balance;
    int pin;
} Account;

int get_next_id() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 1001;
    Account acc;
    int max = 1000;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.account_no > max) max = acc.account_no;
    }
    fclose(fp);
    return max + 1;
}

void create_account() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return;
    }
    Account acc;
    acc.account_no = get_next_id();

    printf("\n--- NEW ACCOUNT CONFIGURATION ---");
    printf("\nYOUR ASSIGNED ACCOUNT NUMBER: %d\n", acc.account_no);
    
    printf("Enter Full Name: ");
    while (getchar() != '\n'); 
    fgets(acc.name, 100, stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;
    
    printf("Initial Deposit Amount: ");
    scanf("%lf", &acc.balance);
    
    printf("Set Your 4-Digit Security PIN: ");
    scanf("%d", &acc.pin);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("\nWelcome to MRIIRS Bank, %s! Your account has been created.\n", acc.name);
}

void deposit_withdraw(int type) { // 1 for deposit, 2 for withdraw
    int id, pin, found = 0;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &id);
    
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) { 
        printf("Error: No account records found.\n"); 
        return; 
    }

    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.account_no == id) {
            printf("Enter PIN: ");
            scanf("%d", &pin);
            if (pin != acc.pin) { 
                printf("Error: Wrong PIN authentication failed.\n"); 
                fclose(fp); 
                return; 
            }

            printf("\n--- WELCOME BACK, %s ---", acc.name);
            printf("\nCurrent Balance: %.2f\n", acc.balance);
            printf("Enter Amount to %s: ", (type == 1) ? "Deposit" : "Withdraw");
            scanf("%lf", &amount);

            if (type == 2 && amount > acc.balance) {
                printf("Error: Insufficient balance available.\n");
            } else if (amount <= 0) {
                printf("Error: Invalid transaction amount.\n");
            } else {
                acc.balance += (type == 1) ? amount : -amount;
                fseek(fp, -(long)sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("Success! Your new balance is: %.2f\n", acc.balance);
            }
            found = 1; 
            break;
        }
    }
    if (!found) printf("Error: Account number %d not found.\n", id);
    fclose(fp);
}

void check_balance() {
    int id, pin, found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &id);
    
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { 
        printf("Error: Database not accessible.\n"); 
        return; 
    }

    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.account_no == id) {
            printf("Enter PIN: ");
            scanf("%d", &pin);
            if (pin != acc.pin) { 
                printf("Error: Authentication failed.\n"); 
                fclose(fp); 
                return; 
            }
            printf("\n--- WELCOME BACK, %s ---", acc.name);
            printf("\nYour Net Account Balance: %.2f\n", acc.balance);
            found = 1; 
            break;
        }
    }
    if (!found) printf("Error: Account not found.\n");
    fclose(fp);
}

void admin_list() {
    char pass[20];
    printf("\nEnter Admin Security Password: ");
    scanf("%s", pass);
    if (strcmp(pass, ADMIN_PASSWORD) != 0) { 
        printf("Access Denied: Incorrect Admin Password.\n"); 
        return; 
    }

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { 
        printf("\nNo account records currently exist.\n"); 
        return; 
    }
    Account acc;
    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-25s %-15s\n", "Acc No", "Account Holder", "Balance");
    printf("------------------------------------------------------------\n");
    while (fread(&acc, sizeof(Account), 1, fp)) {
        printf("%-10d %-25s %-15.2f\n", acc.account_no, acc.name, acc.balance);
    }
    printf("------------------------------------------------------------\n");
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n=================================");
        printf("\n       WELCOME TO MRIIRS BANK");
        printf("\n=================================");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Admin: List All Accounts");
        printf("\n6. Exit");
        printf("\n---------------------------------");
        printf("\nSelect Option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection. Please use numbers.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(choice) {
            case 1: create_account(); break;
            case 2: deposit_withdraw(1); break;
            case 3: deposit_withdraw(2); break;
            case 4: check_balance(); break;
            case 5: admin_list(); break;
            case 6: 
                printf("\nThank you for choosing MRIIRS Bank. Goodbye!\n");
                exit(0);
            default: printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}
