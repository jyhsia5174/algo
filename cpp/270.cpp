// 270. Closest Binary Search Tree Value
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
    int closestValue(TreeNode* root, double target) {
        TreeNode *l = lower(root, target);
        TreeNode *r = upper(root, target);
        
        if( l == NULL )
            return r->val;
        if( r == NULL )
            return l->val;
        
        double l_diff = target - l->val;
        double r_diff = r->val - target;
        if( l_diff <= r_diff )
            return l->val;
        else
            return r->val;
    }
    
    TreeNode *lower( TreeNode *n, const double &val ){
        if( n == NULL ) return NULL;
        
        if( val == n->val ){
            return n;
        }
        else if( val > n->val ){
            TreeNode *r_node = lower(n->right, val);
            if( r_node == NULL )
                return n;
            return r_node;
        }
        else{
            return lower(n->left, val);
        }
    }
    
    TreeNode *upper( TreeNode *n, const double &val ){
        if( n == NULL ) return NULL;
        
        if( val == n->val ){
            return n;
        }
        else if( val < n->val ){
            TreeNode *r_node = upper(n->left, val);
            if( r_node == NULL )
                return n;
            return r_node;
        }
        else{
            return upper(n->right, val);
        }
    }
};
