// 236. Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs( root, p, q );
        return lca;
    }
    
    int dfs( TreeNode* cur_n, TreeNode* p, TreeNode* q ){
        if( lca != NULL ) return 2;
        if( cur_n == NULL ) return 0;
        
        int count = 0;
        if( cur_n == p || cur_n == q ) count++;
        count += dfs( cur_n->left, p, q);
        count += dfs( cur_n->right, p, q);
        if( count == 2 && lca == NULL )
            lca = cur_n; 
        
        return count;
    }
private:
    TreeNode *lca = NULL;
};
