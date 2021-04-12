/*
98. Validate Binary Search Tree
*/

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
    bool isValidBST(TreeNode* root) {
        if( root == nullptr )
            return true;
        
        if( !isValidBST(root->left) )
            return false;
        
        if( root->val <= pre )
            return false;
        
        pre = root->val;
        
        if( !isValidBST(root->right) )
            return false;
        
        return true;
    }
    
private:
    long long int pre = numeric_limits<long long int>::min();
};


/*
98. Validate Binary Search Tree
*/

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
    bool isValidBST(TreeNode* root) {
        if( root == nullptr )
            return true;
        
        TreeNode *left = root->left;
        while( left != nullptr ){
            if( left->val >= root->val )
                return false;
            left = left->right;
        }
        
        TreeNode *right = root->right;
        while( right != nullptr ){
            if( right->val <= root->val )
                return false;
            right = right->left;
        }
        
        return isValidBST( root->left ) && isValidBST(root->right);
    }
};
