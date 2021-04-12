/*
100. Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pS, qS;
        
        pS.push(p);
        qS.push(q);
        while( !pS.empty() && !qS.empty() ){
            TreeNode *pp = pS.top();
            TreeNode *qq = qS.top();
            pS.pop();
            qS.pop();
            
            if( pp == nullptr && qq == nullptr )
                continue;
            else if( pp == nullptr && qq != nullptr )
                return false;
            else if( pp != nullptr && qq == nullptr )
                return false;
            else{
                if( pp->val != qq->val )    
                    return false;
                
                pS.push( pp->left );
                qS.push( qq->left );
                pS.push( pp->right );
                qS.push( qq->right );
            }
        }
        
        return true;
    }
};
