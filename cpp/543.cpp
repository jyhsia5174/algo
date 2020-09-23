// 543. Diameter of Binary Tree
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
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if( root == NULL ) return 0;
        dfs(root);
        return max_L-1;
    }

    int dfs(TreeNode* n){
        if(n == NULL) return 0;
        
        int hl = dfs( n->left );
        int hr = dfs( n->right );
        
        max_L = max(max_L, hl + hr + 1);
        
        return max(hl, hr) + 1;
    }
    
private:
    int max_L = 0;
};
