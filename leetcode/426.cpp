/*
426. Convert Binary Search Tree to Sorted Doubly Linked List
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if( root == nullptr )
            return nullptr;
        
        Node *head = root;
        while( head->left != nullptr )
            head = head->left;
        
        Node *tail = solve(root, nullptr);
        
        head->left = tail;
        tail->right = head;
        
        return head;
    }
    
    Node* solve(Node* node, Node *pre){
        if( node == nullptr )
            return pre;
        
        Node *leftList = solve(node->left, pre);
        node->left = leftList;
        if( leftList != nullptr )
            leftList->right = node;
        Node *rightList = solve(node->right, node);
        
        return rightList;
    }
};
