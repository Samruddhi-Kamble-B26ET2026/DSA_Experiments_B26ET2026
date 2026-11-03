#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
// PUSH operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}
// POP operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}
// DISPLAY operation
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack contents:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
        printf("TOP is at array position: %d\n", top + 1);
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
