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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if( r1 == nullptr && r2 == nullptr )
            return true;
        
        if( r1 == nullptr || r2 == nullptr )
            return false;
        
        if( r1->val != r2->val )
            return false;
        
        bool rr = flipEquiv( r1->right, r2->right );
        bool ll = flipEquiv( r1->left, r2->left );
        
        if( rr && ll )
            return true;
        
        bool rl = flipEquiv( r1->right, r2->left );
        bool lr = flipEquiv( r1->left, r2->right );
        
        if( rl && lr )
            return true;
        
        return false;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2);
    }
    
    bool check(TreeNode* r1, TreeNode* r2){
        bool res = true;
        if( r1 == NULL || r2 == NULL ){
            if( !( r1 == NULL && r2 == NULL ) )
                res = false;
            return res;
        }
        
        if( r1->val != r2->val ){
            res = false;
        }
        else{
            if( !(check(r1->left, r2->left) && check(r1->right, r2->right)) && !(check(r1->left, r2->right) && check(r1->right, r2->left)) )
                res = false;
        }
        
        return res;
    }
};
