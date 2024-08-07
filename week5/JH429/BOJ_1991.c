#include <stdio.h>

typedef struct{
    char parent, leftChild, rightChild;
} Node;

Node nodes[27];

void preorder(char root){
    if (root == '.')
        return;
    
    printf("%c", root);
    preorder(nodes[root - 'A'].leftChild);
    preorder(nodes[root - 'A'].rightChild);
}

void inorder(char root){
    if (root == '.')
        return;
    
    inorder(nodes[root - 'A'].leftChild);
    printf("%c", root);
    inorder(nodes[root - 'A'].rightChild);
}

void postorder(char root){
    if (root == '.')
        return;
    
    postorder(nodes[root - 'A'].leftChild);
    postorder(nodes[root - 'A'].rightChild);
    printf("%c", root);
}


int main() {
    int N;
    char p, l, r;

    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++) {
        scanf("%c %c %c", &p, &l, &r);
        getchar();
        nodes[p - 'A'].parent = p;
        nodes[p - 'A'].leftChild = l;
        nodes[p - 'A'].rightChild = r;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');

    return 0;
    
}