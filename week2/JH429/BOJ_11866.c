#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->rear == NULL) ? 1 : 0;
}

void enq(Queue* q, int num) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = num;
    n->link = NULL;

    if(isEmpty(q)) {
        q->front = n;
        q->rear = n;
    }

    else
        q->rear->link = n;
        q->rear = n;
}

int deq(Queue* q) {
    int data;
    Node* temp = q->front;
    data = temp->data;
    q->front = temp->link;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);

    return data;
}

int main() {
    Queue que;
    int Josephus[1000];
    int N, K;
    init(&que);

    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++) 
        enq(&que, i);

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < K; j++) {
            int temp = deq(&que);
            enq(&que, temp);
            //enq(&que, deq(&que));
        }
        Josephus[i] = deq(&que);
    }

    printf("<");
    for(int i = 0; i < N-1; i++) 
        printf("%d, ", Josephus[i]);

    printf("%d>", Josephus[N-1]);
    
    return 0;
}