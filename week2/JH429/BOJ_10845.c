#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct Node {
    int data;
    struct Node* link;
} Node;

typedef struct {
    Node* front, *rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = NULL;
}

int empty(Queue* q) {
    return (q->front) == NULL ? 1 : 0;
}

void push(Queue* q, int n) { 
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = n;
    temp->link = NULL;

    if(empty(q)) {
        q->front = temp;
        q->rear = temp;
    }

    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

void pop(Queue* q) { 
    Node* temp;
    int data;

    if(empty(q)) {
        printf("-1\n");
        return;
    }
    temp = q->front;
    data = temp->data;
    q->front = temp->link;

    if(q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    printf("%d\n", data);
}

void size(Queue* q) {
    int i = 0;
    Node* temp = q->front;
    while(temp != NULL) {
        temp = temp->link;
        i++;
    }
    printf("%d\n", i); 
}



void front(Queue* q) {
    if(empty(q))
        printf("-1\n");

    else   
        printf("%d\n", q->front->data);
}

void back(Queue* q) {
    if(empty(q))
        printf("-1\n");
    else
        printf("%d\n", q->rear->data);
}


int main() {
    Queue que;
    int N, num;
    char inst[20];

    init(&que);
  
    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++) {
        fgets(inst, sizeof(inst), stdin);
        inst[strlen(inst) - 1] = '\0';

        if(strncmp(inst, "push", 4) == 0) {
            sscanf(inst, "push %d", &num);
            push(&que, num);
        }

        else if(strcmp(inst, "pop") == 0)
            pop(&que);

        else if(strcmp(inst, "size") == 0)
            size(&que);
        
        else if(strcmp(inst, "empty") == 0) {
            printf("%d\n", empty(&que));
        }

        else if(strcmp(inst, "front") == 0)
            front(&que);

        else if(strcmp(inst, "back") == 0)
            back(&que);

        else
            continue;
    }

    return 0;
}