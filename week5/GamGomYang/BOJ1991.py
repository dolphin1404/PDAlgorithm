#1. 입력 노드 수와 노드 정보
n = int(input())
tree = {}
for _ in range(n):
    node , left, right = list(input().split())
    tree[node] = left, right


#2. 전위 순회
def preorder(x):
    if x == '.':
        return
    print(x, end='')      # 현재 노드 방문
    preorder(tree[x][0])  # 왼쪽 자식 방문
    preorder(tree[x][1])  # 오른쪽 자식 방문


#3. 중위 순회
def inorder(x):
    if x == '.':
        return
    inorder(tree[x][0])  # 왼쪽 자식 방문
    print(x, end='')     # 현재 노드 방문
    inorder(tree[x][1])  # 오른쪽 자식 방문


#4. 후위 순회
def postorder(x):
    if x == '.':
        return
    postorder(tree[x][0])  # 왼쪽 자식 방문
    postorder(tree[x][1])  # 오른쪽 자식 방문
    print(x, end='')       # 현재 노드 방문


preorder('A')
print()
inorder('A')
print()
postorder('A')