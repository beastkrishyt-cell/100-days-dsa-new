#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[1000];
int top = -1;
void push(char x) { stack[++top] = x; }
char pop() { return top == -1 ? -1 : stack[top--]; }
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}
int main() {
    char exp[1000];
    if (scanf("%s", exp) != 1) return 0;
    char *e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) printf("%c", *e);
        else if (*e == '(') push(*e);
        else if (*e == ')') {
            char x;
            while ((x = pop()) != '(') printf("%c", x);
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}
// update 1
// update 1
// update 1
// update 1
// update 1
// update 1
// update 1
