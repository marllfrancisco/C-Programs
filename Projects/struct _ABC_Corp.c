// ABC Corp Program 
// records employee infos then;
// determine if loyal or not (working for 10 and greater years)
/* NOTES:
    scanf(" %[^\n]" - accepts string (w/ space)
    structs - collection of data types
*/

#include <stdio.h>

typedef struct {
    char DeptName[64], Position[64];
    int YearHired;
} Department;

typedef struct {
    char EmployeeID[64], EmployeeName[64], EmployeeAddress[100];
    Department dept[3];
} Employees;

Employees emp[3];

void Emp_Rec() {
    FILE *fp = fopen("ABC_Employees.txt", "w"); // Open file for writing
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
 	
    for (int i = 0; i < 3; i++) {
        printf("Emp%d\n", i + 1);
        printf("EmpID: ");
        scanf(" %s", emp[i].EmployeeID); getchar();

        printf("EmpName: ");
        scanf(" %[^\n]", emp[i].EmployeeName);

        printf("EmpAddr: ");
        scanf(" %[^\n]", emp[i].EmployeeAddress);

        printf("DeptName: ");
        scanf(" %[^\n]", emp[i].dept[i].DeptName);

        printf("Position: ");
        scanf(" %[^\n]", emp[i].dept[i].Position);

        printf("YearHired: ");
        scanf("%d", &emp[i].dept[i].YearHired); 

        // Write to file
        fprintf(fp, "%s|%s|%s|%s|%s|%d\n",
                emp[i].EmployeeID,
                emp[i].EmployeeName,
                emp[i].EmployeeAddress,
                emp[i].dept[i].DeptName,
                emp[i].dept[i].Position,
                emp[i].dept[i].YearHired);

        printf("\n");
    }

    fclose(fp);
}

void Display_File() {
    FILE *fp = fopen("ABC_Employees.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    char line[256];
    printf("---- Contents of ABC_Employees.txt ----\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line); // Already includes newline
    }
    printf("\n-------------------------------------\n");

    fclose(fp);
}

void Loy_Dis() {
    int years[3];
    printf("\nLoyal Employees (10 years and more)");
    printf("\n%-10s %-10s %-10s %-10s\n", "NAME", "DEPTNAME", "POSITION", "YEARS");

    for (int i = 0; i < 3; i++) {
        years[i] = 2025 - emp[i].dept[i].YearHired;
        if (years[i] >= 10) {
            printf("%-10s %-10s %-10s %-10d\n",
                   emp[i].EmployeeName,
                   emp[i].dept[i].DeptName,
                   emp[i].dept[i].Position,
                   years[i]);
        }
    }
}

int main() {
    Emp_Rec();
    Display_File();
    Loy_Dis();
    return 0;
}

