#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char str[100];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    for(i=0; str[i] != '\0'; i++)
        push(str[i]);

    printf("Reversed string: ");

    while(top != -1)
        printf("%c", pop());

    return 0;
