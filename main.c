
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
