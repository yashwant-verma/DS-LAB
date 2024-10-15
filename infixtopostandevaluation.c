#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function to return the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(const char *infix, char *postfix) {
    char stack[MAX];
    int top = -1; // Stack top
    int j = 0;    // Postfix index

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to output
        if (isalnum(c)) {
            postfix[j++] = c;
        } 
        // If the character is '(', push it to stack
        else if (c == '(') {
            stack[++top] = c;
        } 
        // If the character is ')', pop from stack to output until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Pop the '('
        } 
        // An operator is encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c; // Push the current operator
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char *postfix) {
    int stack[MAX];
    int top = -1; // Stack top

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isspace(c)) {
            continue; // Skip spaces
        }

        // If the scanned character is an operand (number)
        if (isdigit(c)) {
            stack[++top] = c - '0'; // Convert char to int
        } 
        // If the scanned character is an operator
        else {
            int val1 = stack[top--]; // Pop two operands
            int val2 = stack[top--];

            // Perform the operation
            switch (c) {
                case '+':
                    stack[++top] = val2 + val1;
                    break;
                case '-':
                    stack[++top] = val2 - val1;
                    break;
                case '*':
                    stack[++top] = val2 * val1;
                    break;
                case '/':
                    stack[++top] = val2 / val1;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }

    // The final result will be the only item on the stack
    return stack[top];
}

// Main function
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}