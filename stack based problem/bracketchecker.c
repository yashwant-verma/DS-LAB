#include<stdio.h>
#include<stdbool.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    if(top >= SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return '\0'; // Return null character in case of underflow
    } else {
        return stack[top--];
    }
}

bool checker(char brackets[]) {
    int i = 0;
    char item;
    
    while(brackets[i] != '\0') {
        item = brackets[i++];
        
        if(item == '(' || item == '[' || item == '{') {
            push(item);
        } else if(item == ')' || item == ']' || item == '}') {
            if(top == -1) { // Stack should not be empty when closing bracket appears
                return false;
            }
            char popped = pop();
            if((item == ')' && popped != '(') ||
               (item == '}' && popped != '{') ||
               (item == ']' && popped != '[')) {
                return false;
            }
        }
    }
    
    // If the stack is not empty at the end, brackets are unbalanced
    return (top == -1);
}

int main() {
    char exp[SIZE];
    printf("Enter an expression: ");
    fgets(exp, SIZE, stdin); // Use fgets to avoid buffer overflow

    if(checker(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}