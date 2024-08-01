#include <iostream>
#include <unordered_map>
using namespace std;

// 노드 구조체 정의
struct Node {
    char key;
    Node* left;
    Node* right;
    
    Node(char k) : key(k), left(NULL), right(NULL) {}
};

unordered_map<char, Node*> nodeMap; // 노드들을 저장하는 맵

// 중위 순회
void inorderTraversal(Node* ptr) {
    if (ptr) {
        inorderTraversal(ptr->left);  // 왼쪽 서브트리를 순회
        cout << ptr->key;             // 노드의 key 값 출력
        inorderTraversal(ptr->right); // 오른쪽 서브트리를 순회
    }
}

// 전위 순회
void preorderTraversal(Node* ptr) {
    if (ptr) {
        cout << ptr->key;             // 노드의 key 값 출력
        preorderTraversal(ptr->left); // 왼쪽 서브트리를 순회
        preorderTraversal(ptr->right);// 오른쪽 서브트리를 순회
    }
}

// 후위 순회
void postorderTraversal(Node* ptr) {
    if (ptr) {
        postorderTraversal(ptr->left); // 왼쪽 서브트리를 순회
        postorderTraversal(ptr->right);// 오른쪽 서브트리를 순회
        cout << ptr->key;              // 노드의 key 값 출력
    }
}

int main() {
    int N;
    cin >> N;
    
    // 트리 구성
    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        
        if (nodeMap.find(parent) == nodeMap.end()) {
            nodeMap[parent] = new Node(parent);
        }
        
        if (left != '.') {
            if (nodeMap.find(left) == nodeMap.end()) {
                nodeMap[left] = new Node(left);
            }
            nodeMap[parent]->left = nodeMap[left];
        }
        
        if (right != '.') {
            if (nodeMap.find(right) == nodeMap.end()) {
                nodeMap[right] = new Node(right);
            }
            nodeMap[parent]->right = nodeMap[right];
        }
    }
    
    // 루트 노드 (항상 'A'임)
    Node* root = nodeMap['A'];
    
    // 전위 순회
    preorderTraversal(root);
    cout << endl;
    
    // 중위 순회
    inorderTraversal(root);
    cout << endl;
    
    // 후위 순회
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}
