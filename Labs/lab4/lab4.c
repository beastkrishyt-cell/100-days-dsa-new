#include <stdio.h>
#include <math.h>
#define MAX 100


char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x, y;

    while (infix[i] != '\0') {
        x = infix[i];

        if (isalnum(x)) {
            postfix[j++] = x;
        }
        else if (x == '(') {
            push(x);
        }
        else if (x == ')') {
            while ((y = pop()) != '(')
                postfix[j++] = y;
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(x))
                postfix[j++] = pop();
            push(x);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}
