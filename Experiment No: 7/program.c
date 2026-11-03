#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

int stack[MAX];
int top = -1;

// PUSH operation
void push(int value)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// POP operation
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i, a, b, result;
    for (i = 0; postfix[i] != '\0'; i++)
    {

        // If character is a digit, push it
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }

        // If character is an operator
        else
        {
            b = pop();
            a = pop();
            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
                case '^':
                    result = pow(a, b);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char postfix[MAX];
    int result;
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}

