// 938. Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if( root == NULL ) return 0;
        
        int l_sum = rangeSumBST(root->left, L, R);
        int r_sum = rangeSumBST(root->right, L, R);
        
        if( root->val >= L && root->val <= R)
            return l_sum + r_sum + root->val;
        return l_sum + r_sum;
    }
};
