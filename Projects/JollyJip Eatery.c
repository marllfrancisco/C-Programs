#include <stdio.h>
#include <string.h>

#define MAX_BILLS 50
#define MAX_MENU 50

struct menuItem {
    char code[10];
    char description[50];
    float price;
};

struct orderItem {
    struct menuItem item;
    int quantity;
    float subTotal;
};

struct date {
    char month[10];
    int day;
    int year;
};

struct billing {
    struct orderItem orders[50];
    int orderCount;
    float totalBill;
    float discount;
    float netBill;
    float tendered;
    float change;
    struct date date;
};

struct menuItem menu[MAX_MENU] = {
    {"SP1", "Solo Package 1", 149.00},
    {"SP2", "Solo Package 2", 199.00},
    {"FP1", "Family Package 1", 749.00},
    {"FP2", "Family Package 2", 799.00},
    {"BP1", "Barkada Package 1", 349.00},
    {"BP2", "Barkada Package 2", 399.00},
    {"BF1", "Barkada Fries", 119.00},
    {"B1", "Beef Burger", 79.00},
    {"B2", "Beef Cheese Burger", 89.00},
    {"Soda", "Coke 1.5L", 69.00},
    {"ExR", "Extra Rice", 39.00},
    {"BW", "Bottled Water", 25.00}
};

int menuSize = 12;

//FUNCTION PROTOTYPE

//FOR BILLING SUB MODULE
void billingSubModule(struct billing bills[], int *billCount);
void inputAndBill(struct billing bills[], int *billCount);
void getOrder(struct billing *bill);
void getDate(struct date *date);
void displayMenu(struct menuItem *menu);
int findMenu(char *code);
void calculateNetBill(struct billing *bill, struct date date, char confirmPWD, char confirmSenior);
void discount(struct billing *bill, struct date date, char confirmPWD, char confirmSenior);
void paymentnChange(struct billing *bill);
void displayBill(struct billing *bill, struct date date);
void generateTotalSale(struct billing bills[], int billCount);

//FOR FILE MAINTENANCE
void fileMaintenance(struct menuItem *menu);
void addMenu(struct menuItem *menu);
void updateItem(struct menuItem *menu);

//FOR WRITING TO FILE
int writeMenuToFile(struct menuItem *menu, const char *filename);

//FOR VALIDATION
int isYesOrNo(char c);

//MAIN PROGRAM
int main() {
    struct billing bills[MAX_BILLS];
    int billCount = 0;
    char menuAgain;
    int choose;
    int exitFlag = 0;

    do {
        printf("\n\tMAIN MENU\n");
        printf("\n1. BILLING SUB-MODULE");
        printf("\n   1. ORDERING AND RECEIPT");
        printf("\n   2. GENERATE DAILY TOTAL SALES");
        printf("\n   3. DISPLAY MENU");
        printf("\n2. FILE MAINTENANCE");
        printf("\n   1. ADD NEW RECORD/S");
        printf("\n   2. UPDATE RECORD/S");
        printf("\n      1. MENU");
        printf("\n      2. PRICE");
        printf("\n3. Exit");

        do {
            printf("\nCHOOSE TRANSACTION: ");
            scanf("%d", &choose);
            getchar();

            if (choose < 1 || choose > 3) {
                printf("\n---Choose from the options only---\n");
            }
        } while (choose < 1 || choose > 3);

        switch(choose){
            case 1: billingSubModule(bills, &billCount); break;
            case 2: fileMaintenance(menu); break;
            case 3: printf("\nClosing the program...\n"); exitFlag = 1; break;
            default: break;
        }

        if (!exitFlag) {
            do {
                printf("\nUse Menu again?(Y/N): ");
                scanf(" %c", &menuAgain);
            } while (!isYesOrNo(menuAgain));
        }
    } while ((menuAgain == 'y' || menuAgain == 'Y') && !exitFlag);

    printf("\nDONE!");
    return 0;
}

//BILLING SUB MODULE
void billingSubModule(struct billing bills[], int *billCount) {
    int chooseSubModule;

    do {
        printf("\nChoose Sub-Module option: ");
        scanf("%d", &chooseSubModule);
        getchar();

        if (!(chooseSubModule == 1 || chooseSubModule == 2 || chooseSubModule == 3)){
            printf("\n---Choose from the options only---\n");
        }
    } while (!(chooseSubModule == 1 || chooseSubModule == 2 || chooseSubModule == 3));

    switch(chooseSubModule){
        case 1: inputAndBill(bills, billCount); break;
        case 2: generateTotalSale(bills, *billCount); break;
        case 3: displayMenu(menu); break;
        default: break;
    }
}

void inputAndBill(struct billing bills[], int *billCount) {
    char orderAgain, confirmPWD, confirmSenior, anotherCustomer;
    struct date date;

    do {
        struct billing *bill = &bills[*billCount];
        bill->orderCount = 0;

        getDate(&date);

        do {
            getOrder(bill);

            do {
                printf("\nInput another item?(y/n): ");
                scanf(" %c", &orderAgain);

                if (!isYesOrNo(orderAgain)){
                    printf("\n---Invalid Input---\n");
                }
            } while (!isYesOrNo(orderAgain));
        } while (orderAgain == 'Y' || orderAgain == 'y');

        do {
            printf("\nIs the customer PWD?(y/n): ");
            scanf(" %c", &confirmPWD);

            if (!isYesOrNo(confirmPWD)) {
                printf("\n---Invalid Input---\n");
            }
        } while (!isYesOrNo(confirmPWD));

        do {
            printf("\nIs the customer Senior?(y/n): ");
            scanf(" %c", &confirmSenior);

            if (!isYesOrNo(confirmSenior)) {
                printf("\n---Invalid Input---\n");
            }
        } while (!isYesOrNo(confirmSenior));

        bill->date = date;

        calculateNetBill(bill, date, confirmPWD, confirmSenior);
        paymentnChange(bill);
        displayBill(bill, date);

        (*billCount)++;

        do {
            printf("\nAnother Customer?(y/n): ");
            scanf(" %c", &anotherCustomer);

            if (!isYesOrNo(anotherCustomer)) {
                printf("\n---Invalid Input---\n");
            }
        } while (!isYesOrNo(anotherCustomer));
    } while (anotherCustomer == 'y' || anotherCustomer == 'Y');
}

void getOrder(struct billing *bill) {
    int index, qty;
    char code[10];

    do {
        printf("\nInput item code: ");
        scanf(" %s", code);
        index = findMenu(code);
        if (index == -1) {
            printf("\n---Invalid Code Input---\n");
        }
    } while (index == -1);

    printf("Input quantity: ");
    scanf("%d", &qty);

    bill->orders[bill->orderCount].item = menu[index];
    bill->orders[bill->orderCount].quantity = qty;
    bill->orders[bill->orderCount].subTotal = qty * menu[index].price;
    bill->orderCount++;
}

void getDate(struct date *date) {
    int valid;

    do {
        printf("\nInput date (e.g., June 17 2025): ");
        valid = scanf("%s %d %d", date->month, &date->day, &date->year);
        getchar();
        
        if(valid != 3 || date->day > 31 || date->day <= 0 || date->year <= 0){
            printf("\n---Invalid Time Format---\n");
            valid = 0;
        }
    } while (!valid);
}

void calculateNetBill(struct billing *bill, struct date date, char confirmPWD, char confirmSenior) {
    bill->totalBill = 0;
    for (int i = 0; i < bill->orderCount; i++)
        bill->totalBill += bill->orders[i].subTotal;

    discount(bill, date, confirmPWD, confirmSenior);
    bill->netBill = bill->totalBill - bill->discount;
}

int isPWD(char confirmPWD) {
    return (confirmPWD == 'Y' || confirmPWD == 'y');  //return true or 1
}

int isSenior(char confirmSenior) {
    return (confirmSenior == 'Y' || confirmSenior == 'y'); //return true or 1
}

void discount(struct billing *bill, struct date date, char confirmPWD, char confirmSenior) {
    float total = bill->totalBill;
    bill->discount = 0;

    if (total >= 500 && total <= 2000 && 
        (strcmp(date.month, "May") == 0 || strcmp(date.month, "may") == 0 || 
        strcmp(date.month, "June") == 0 || strcmp(date.month, "june") == 0)) {
        bill->discount += total * 0.02;
    } 
    
    if (isPWD(confirmPWD) && isSenior(confirmSenior)) {
        bill->discount += total * 0.05;
    } else if (isSenior(confirmSenior) && !isPWD(confirmPWD)) {
        bill->discount += total * 0.15;
    } else if (isPWD(confirmPWD) && !isSenior(confirmSenior)){
        bill->discount += total * 0.20;
    }
}

void paymentnChange(struct billing *bill) {
    float payment;
    do {
        printf("\nNet Bill: %.2f\n", bill->netBill);
        printf("Enter amount paid: ");
        scanf("%f", &payment);

        if (payment < bill->netBill)
            printf("\n---Insufficient Funds. Try again---\n");
    } while (payment < bill->netBill);

    bill->tendered = payment;
    bill->change = payment - bill->netBill;
}

void displayBill(struct billing *bill, struct date date) {
    printf("\n\n\t----- BILLING STATEMENT -----\n");
    printf("Date: %s %d, %d\n", date.month, date.day, date.year);
    printf("\n%-8s | %-23s | %-6s | %-8s | %-8s\n", "Code", "Description", "Price", "Qty", "Amount");

    for (int i = 0; i < bill->orderCount; i++) {
        printf("%-8s | %-23s | %-6.2f | %-8d | %-8.2f\n",
               bill->orders[i].item.code,
               bill->orders[i].item.description,
               bill->orders[i].item.price,
               bill->orders[i].quantity,
               bill->orders[i].subTotal);
    }

    printf("\nTotal: %.2f", bill->totalBill);
    printf("\nDiscount: %.2f", bill->discount);
    printf("\nNet Bill: %.2f", bill->netBill);
    printf("\nTendered: %.2f", bill->tendered);
    printf("\nChange: %.2f\n", bill->change);
}

void displayMenu(struct menuItem *menu) {
    printf("\n--- JOLLY-JIP MENU ---\n");
    printf("%-8s | %-23s | %-6s\n", "Code", "Description", "Price");

    for (int i = 0; i < menuSize; i++) {
        printf("%-8s | %-23s | %.2f\n", menu[i].code, menu[i].description, menu[i].price);
    }
}

int findMenu(char *code) {
    for (int i = 0; i < menuSize; i++) {
        if (strcmp(menu[i].code, code) == 0)
            return i;
    }
    return -1;
}

//FILE MAINTENANCE
void fileMaintenance(struct menuItem *menu){
    int chooseFileM;

    do {
        printf("\nCHOOSE FILE MAINTENANCE OPTION: ");
        scanf("%d", &chooseFileM);
        getchar();

        if (!(chooseFileM == 1 || chooseFileM == 2)){
            printf("\n--Choose from the options only---\n");
        }
    } while (!(chooseFileM == 1 || chooseFileM == 2));

    switch(chooseFileM){
        case 1: addMenu(menu);
                break;
        case 2: updateItem(menu);
                break;
        default: break;;
    }
}

void addMenu(struct menuItem *menu){
    int add, codeExist;

    printf("\nHow many item to be added: ");
    scanf("%d", &add);
    getchar();

    if (menuSize + add > 50) {
        printf("\n---Cannot add %d items. Only %d slots remaining---\n", add, 50 - menuSize);
        return;
    }

    if (add <= 0){
        printf("\n---No item will be added---\n");
    } else {
        printf("\n---Add New Item to Menu---\n");

        for(int i = 0; i < add; i++){
            do {
                codeExist = 0;
                printf("\nItem Code: ");
                scanf(" %s", menu[menuSize].code);
                getchar();

                for (int j = 0; j < menuSize; j++) {
                    if (strcmp(menu[menuSize].code, menu[j].code) == 0) {
                        printf("\n---Item Code is already used---\n");
                        codeExist = 1;
                        break;
                    }
                }
            } while (codeExist);

            printf("Description: ");
            fgets(menu[menuSize].description, sizeof(menu[menuSize].description), stdin);
            menu[menuSize].description[strcspn(menu[menuSize].description, "\n")] = 0;
        
            do {
                printf("Price: ");
                scanf("%f", &menu[menuSize].price);

                if (menu[menuSize].price <= 0){
                    printf("\n---Input Non-negative Number---\n");
                }
            } while (menu[menuSize].price <= 0);
            
            menuSize++;
        }
    
        printf("\n---Added to the Menu---\n");

        writeMenuToFile(menu, "menu.txt");
    }
}

void updateItem(struct menuItem *menu){
    int found, index, chooseUpd;
    char updateAgain, code[16];
    
    do{
        found = 0;

        do {
            printf("\nCHOOSE UPDATE OPTION: ");
            scanf("%d", &chooseUpd);
            getchar();

            if (!(chooseUpd == 1 || chooseUpd == 2)){
                printf("\n---Choose from the options only---\n");
            }
        } while (!(chooseUpd == 1 || chooseUpd == 2));

        printf("\nEnter Item Code to be updated: ");
        scanf(" %s", code);
        getchar();

        switch(chooseUpd){
            case 1: for (int i = 0; i < menuSize; i++){
                        if(strcmp(menu[i].code, code) == 0){
                            printf("\nItem Descripton Update \n");
                            printf("Item Code: ");
                            scanf(" %s", menu[i].code);
                            getchar();

                            printf("Item Description: ");
                            fgets(menu[i].description, sizeof(menu[i].description), stdin);
                            menu[i].description[strcspn(menu[i].description, "\n")] = 0;

                            found = 1;
                            break;
                        }
                    }

                    if (!found){
                            printf("\n---Item not found---\n");
                    }

                    break;
            case 2: for (int i = 0; i < menuSize; i++){
                        if(strcmp(menu[i].code, code) == 0){
                            printf("\nItem Price Update");
                            do {
                                printf("\nItem Price: ");
                                scanf("%f", &menu[i].price);

                                if (menu[i].price <= 0){
                                    printf("\n---Input Non-negative Number---");
                                }
                            } while (menu[i].price <= 0);

                            found = 1;
                            break;
                        }
                    }

                    if (!found){
                        printf("\n---Item not found---\n");
                    }

                    break;
            default: printf("\n---Choose from the options only---\n");
        }

        if (found){
            printf("\n---Updated---\n");
            writeMenuToFile(menu, "menu.txt");
        }

        do {
            printf("\nUpdate other Item Menu?(Y/N): ");
            scanf(" %c", &updateAgain);

            if (!isYesOrNo(updateAgain)){
                printf("\n---Invalid Input---\n");
            }
        } while (!isYesOrNo(updateAgain));
    } while (updateAgain == 'y' || updateAgain == 'Y');
}

void generateTotalSale(struct billing *bills, int billCount){
    float totalSales = 0, totalDiscount = 0, totalNetBill = 0;

    printf("\nDAILY TOTAL SALES REPORT\n");

    if (billCount == 0) {
        printf("\n---No transactions yet.---\n");
        return;
    }

    printf("\nAs of %s %d %d\n", bills[0].date.month, bills[0].date.day, bills[0].date.year);


    for (int i = 0; i < billCount; i++){
        totalSales += bills[i].totalBill;
        totalDiscount += bills[i].discount;
        totalNetBill += bills[i].netBill;
    }

    printf("\nTotal Billing for the day: %.2f", totalSales);
    printf("\nTotal Discount provided for the day: %.2f", totalDiscount);
    printf("\nTotal Net Billing for the day: %.2f\n", totalNetBill);
}

//FILE HANDLING
int writeMenuToFile(struct menuItem *menu, const char *filename){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        printf("\n---Error Opening File---\n");
        return 1;
    }

    for(int i = 0; i < menuSize; i++){
        fprintf(fp, "%-8s | %-23s | %-10.2f\n", 
            menu[i].code, 
            menu[i].description, 
            menu[i].price);
    }

    printf("\n--Written to File Successfully--\n");

    return 0;
}

int isYesOrNo(char c) {
    return c == 'y' || c == 'Y' || c == 'n' || c == 'N';
}