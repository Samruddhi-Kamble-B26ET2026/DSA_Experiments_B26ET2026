#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

// INSERT operation (PUSH)
void insert() {
    int value;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d inserted into stack.\n", value);
}

// DELETE operation (POP)
void delete() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    temp = top;
    printf("%d deleted from stack.\n", top->data);
    top = top->next;
    free(temp);
}

// DISPLAY operation
void display() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
