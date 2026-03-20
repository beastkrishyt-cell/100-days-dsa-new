#include <stdio.h>
#include <ctype.h>
#include <string.h>
int stack[1000];
int top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int main() {
    char exp[1000];
    if (scanf("%s", exp) != 1) return 0;
    char *e = exp;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (*e) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
        e++;
    }
    printf("%d\n", pop());
    return 0;
}
