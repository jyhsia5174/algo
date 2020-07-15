// 199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if( root == NULL ) return ans;
        
        queue<TreeNode*> Q, Q_tmp;
        Q.push(root);
        ans.push_back(root->val);
        while( !Q.empty() ){
            while( !Q.empty() ){
                TreeNode *n = Q.front();
                Q.pop();
                if( n->right != NULL ) Q_tmp.push( n->right );
                if( n->left != NULL ) Q_tmp.push( n->left );
            }
            swap( Q, Q_tmp );
            if( !Q.empty() )
                ans.push_back( Q.front()->val );
        }
        
        return ans;
    }
};
