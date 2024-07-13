#include <stdio.h>
#include <string.h>

#define MAXNUMBER 10000

typedef struct {
    int data[MAXNUMBER];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int empty(Queue *q) {
    return q->rear == q->front;
}

void push(Queue *q, int value) {
    q->data[q->rear] = value;
    q->rear++;
}

int pop(Queue *q) {
    if (empty(q)) {
        return -1;
    } else {
        return q->data[q->front++];
    }
}

int front(Queue *q) {
    if (empty(q)) {
        return -1;
    } else {
        return q->data[q->front];
    }
}

int back(Queue *q) {
    if (empty(q)) {
        return -1;
    } else {
        return q->data[q->rear - 1];
    }
}

int size(Queue *q) {
    return q->rear - q->front;
}

int isEmpty(Queue *q) {
    return empty(q);
}

int main() {
    int n;
    char command[6];
    int value;

    Queue q;

    init(&q);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d", &value);
            push(&q, value);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(&q));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&q));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", isEmpty(&q));
        } else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&q));
        } else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&q));
        }
    }

    return 0;
}
