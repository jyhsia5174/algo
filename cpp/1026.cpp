// 1026. Maximum Difference Between Node and Ancestor
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
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int ans = 0;
    pair<int, int> dfs(TreeNode* n){
        if( n == NULL ) return {-1, -1};
        
        auto l = dfs( n->left );
        auto r = dfs( n->right );
        
        int min_ch, max_ch;
        if( l.first != -1 && r.first != -1 ){
            min_ch = min( l.first, r.first );
            max_ch = max( l.second, r.second );
        }
        else if( l.first == -1 && r.first != -1 ){
            min_ch = r.first;
            max_ch = r.second;
        }
        else if( l.first != -1 && r.first == -1){
            min_ch = l.first;
            max_ch = l.second;
        }
        else{
            min_ch = max_ch = -1;
        }
        
        if( min_ch != -1 && max_ch != -1 ){
            ans = max( ans, max( abs( n->val - min_ch )  , abs( n->val - max_ch )));
        }
    
        if( min_ch == -1 && max_ch == -1 )
            return {n->val, n->val};
        
        return { min(n->val, min_ch), max(n->val, max_ch) };
    }
};
