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
    return (q->rear + 1) % MAX == q->front;
}

int enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return 0;
    }

    // First element
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->arr[q->rear] = value;

    return 1;
}

int dequeue(struct Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return 0;
    }

    *value = q->arr[q->front];

    // Last element was removed
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
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

    int i = q->front;

    while (1) {
        printf("%d ", q->arr[i]);

        if (i == q->rear)
            break;

        i = (i + 1) % MAX;
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

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("\nAfter adding more elements:\n");
    display(&q);

    if (peek(&q, &value)) {
        printf("\nFront element: %d\n", value);
    }

    return 0;
}
