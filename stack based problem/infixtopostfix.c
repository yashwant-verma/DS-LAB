#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>// becase we are usnigisalnum() to check !
#define MAX 100//using macros to defin the size of the stack
char stack[MAX];
int top = -1;
void push(char item) {
if (top >= MAX - 1) {
printf("Stack Overflow\n");
} else {
stack[++top] = item;
}
}
char pop() {
if (top < 0) {
printf("Stack Underflow\n");
return -1;
} else {
return stack[top--];
}
}
int precedence(char symbol) {
switch (symbol) {
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
default:
return 0;
}
}
int isOperator(char symbol) {
return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol ==
'^');
}
void infixToPostfix(char infix[], char postfix[]) {
int i = 0, j = 0;
char item, x;
while ((item = infix[i++]) != '\0') {
if (isalnum(item)) {
postfix[j++] = item;
} else if (item == '(') {
push(item);
} else if (item == ')') {
    while ((x = pop()) != '(') {

postfix[j++] = x;

}
} else if (isOperator(item)) {
while (top != -1 && precedence(stack[top]) >= precedence(item)) {
postfix[j++] = pop();
}
push(item);
}
}
while (top != -1) {
postfix[j++] = pop();
}
postfix[j] = '\0';
}
int main() {
char infix[MAX], postfix[MAX];
printf("Enter infix expression: ");
gets(infix);
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}