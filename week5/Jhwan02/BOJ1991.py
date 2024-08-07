import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def preorder(parent, child):
    print(parent,end="")
    if child[0] != '.':
        preorder(child[0],tree[child[0]])
    if child[1] != '.':    
        preorder(child[1],tree[child[1]])

def inorder(parent, child):
    if child[0] != '.':
        inorder(child[0],tree[child[0]])
    print(parent,end="")
    if child[1] != '.':    
        inorder(child[1],tree[child[1]])

def postorder(parent, child):
    if child[0] != '.':
        postorder(child[0],tree[child[0]])
    if child[1] != '.':    
        postorder(child[1],tree[child[1]])
    print(parent,end="")




n = int(input())
tree = {}
for _ in range(n):
    root, left, right = input().split()
    tree[root]=[left,right]

preorder('A',tree['A'])
print("")
inorder('A',tree['A'])
print("")
postorder('A',tree['A'])