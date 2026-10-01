#include <stdio.h>
#define MAX 50

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(const struct Stack *s) {
    return s->top == -1;
}

int isFull(const struct Stack *s) {
    return s->top == MAX - 1;
}

int push(struct Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return 0;
    }

    s->arr[++s->top] = val;
    return 1;
}

int pop(struct Stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return 0;
    }

    *value = s->arr[s->top--];
    return 1;
}

int peek(const struct Stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return 0;
    }

    *value = s->arr[s->top];
    return 1;
}

void display(const struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main(void) {
    struct Stack s;
    int value;

    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("After pushing values:\n");
    display(&s);

    pop(&s, &value);
    pop(&s, &value);

    printf("\nAfter popping values:\n");
    display(&s);

    if (peek(&s, &value)) {
        printf("\nTop element: %d\n", value);
    }

    return 0;
}
