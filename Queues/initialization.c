#include <stdio.h>
#define MAX 50

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(const struct Queue *q) {
    return q->front == -1;
}

int isFull(const struct Queue *q) {
    return q->rear == MAX - 1;
}

int enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return 0;
    }

    // First element
    if (q->front == -1) {
        q->front = 0;
    }

    q->arr[++q->rear] = value;

    return 1;
}

int dequeue(struct Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return 0;
    }

    *value = q->arr[q->front++];

    // Queue becomes empty
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }

    return 1;
}

int peek(const struct Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return 0;
    }

    *value = q->arr[q->front];

    return 1;
}

void display(const struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

int main(void) {
    struct Queue q;
    int value;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("After enqueue:\n");
    display(&q);

    dequeue(&q, &value);
    dequeue(&q, &value);

    printf("\nAfter dequeue:\n");
    display(&q);

    if (peek(&q, &value)) {
        printf("\nFront element: %d\n", value);
    }

    return 0;
}
