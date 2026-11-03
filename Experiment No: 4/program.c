#include <stdio.h>
#include <string.h>
#define MAX 100

// Structure for employee
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

// Function declarations
void create(struct Employee emp[], int *n);
void display(struct Employee emp[], int n);
void modify(struct Employee emp[], int n);
void append(struct Employee emp[], int *n);
void search(struct Employee emp[], int n);
void sort(struct Employee emp[], int n);

int main() {
    struct Employee emp[MAX];
    int n = 0;
    int choice;
    do {
        printf("\n========== EMPLOYEE DATABASE ==========\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Modify\n");
        printf("4. Append\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Exit\n");
        printf("=======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create(emp, &n);
                break;
            case 2:
                display(emp, n);
                break;
            case 3:
                modify(emp, n);
                break;
            case 4:
                append(emp, &n);
                break;
            case 5:
                search(emp, n);
                break;
            case 6:
                sort(emp, n);
                break;
            case 7:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

// CREATE
void create(struct Employee emp[], int *n) {
    int i;
    printf("\nEnter number of employees: ");
    scanf("%d", n);
    if (*n > MAX) {
        printf("Maximum %d employees can be stored.\n", MAX);
        *n = MAX;
    }
    for (i = 0; i < *n; i++) {
        printf("\nEnter details of Employee %d\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);
        printf("Department: ");
        scanf(" %[^\n]", emp[i].department);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    printf("\nEmployee database created successfully!\n");
}

// DISPLAY
void display(struct Employee emp[], int n) {
    int i;
    if (n == 0) {
        printf("\nDatabase is empty!\n");
        return;
    }
    printf("\n================ EMPLOYEE DETAILS ================\n");
    printf("%-10s %-20s %-20s %-10s\n",
           "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-20s %.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].department,
               emp[i].salary);
    }
}

// MODIFY
void modify(struct Employee emp[], int n) {
    int id, i, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            found = 1;
            printf("\nEnter new details:\n");
            printf("New Name: ");
            scanf(" %[^\n]", emp[i].name);
            printf("New Department: ");
            scanf(" %[^\n]", emp[i].department);
            printf("New Salary: ");
            scanf("%f", &emp[i].salary);
            printf("\nEmployee record modified successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found!\n", id);
    }
}

// APPEND
void append(struct Employee emp[], int *n) {
    if (*n >= MAX) {
        printf("\nDatabase is full!\n");
        return;
    }
    printf("\nEnter details of new employee:\n");
    printf("Employee ID: ");
    scanf("%d", &emp[*n].id);
    printf("Name: ");
    scanf(" %[^\n]", emp[*n].name);
    printf("Department: ");
    scanf(" %[^\n]", emp[*n].department);
    printf("Salary: ");
    scanf("%f", &emp[*n].salary);
    (*n)++;
    printf("\nEmployee appended successfully!\n");
}

// SEARCH
void search(struct Employee emp[], int n) {
    int id, i, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            found = 1;
            printf("\nEmployee Found!\n");
            printf("Employee ID : %d\n", emp[i].id);
            printf("Name        : %s\n", emp[i].name);
            printf("Department  : %s\n", emp[i].department);
            printf("Salary      : %.2f\n", emp[i].salary);
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found!\n", id);
    }
}

// SORT
void sort(struct Employee emp[], int n) {
    int i, j;
    struct Employee temp;

    // Sort by Employee ID in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (emp[j].id > emp[j + 1].id) {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
    printf("\nEmployee records sorted by ID successfully!\n");
}
