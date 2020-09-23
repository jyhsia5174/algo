// 173. Binary Search Tree Iterator
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    void push_left(TreeNode* n){
        while( n != NULL ){
            S.push(n);
            n = n->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n = S.top();
        S.pop();
        push_left(n->right);
        return n->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if( S.empty() ) return false;
        return true;
    }

private:
    stack<TreeNode*> S;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
