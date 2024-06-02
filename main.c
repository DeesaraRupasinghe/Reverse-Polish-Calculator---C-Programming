
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}


double peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}


void processInstruction(char instruction, Stack *s) {
    double a, b;
    switch (instruction) {
        case '+':
            b = pop(s);
            a = pop(s);
            push(s, a + b);
            break;
        case '-':
            b = pop(s);
            a = pop(s);
            push(s, a - b);
            break;
        case '*':
            b = pop(s);
            a = pop(s);
            push(s, a * b);
            break;
        case '/':
            b = pop(s);
            a = pop(s);
            if (b == 0) {
                printf("Division by zero error\n");
                exit(1);
            }
            push(s, a / b);
            break;
        case '=':
            printf("%lf\n", peek(s));
            break;
        default:
            printf("Invalid instruction: %c\n", instruction);
            exit(1);
    }
}

void parseAndProcessInput(char *input, Stack *stack) {
    char *ptr = input;
    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        if (isdigit(ptr) || (*ptr == '-' && isdigit((ptr + 1)))) {
            char *end;
            double value = strtod(ptr, &end);
            push(stack, value);
            ptr = end;
        } else {
            processInstruction(*ptr, stack);
            ptr++;
            }
        }
    }

int main() {
    Stack stack;
    initStack(&stack);

    char input[100];
    printf("Enter RPN expression (separated by spaces and end with '='): ");
    fgets(input, sizeof(input), stdin);

    parseAndProcessInput(input, &stack);

    return 0;
}
