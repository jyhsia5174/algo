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
    
    unordered_set<int> rm_node;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        rm_node.insert( to_delete.begin(), to_delete.end() );
        
        vector<TreeNode*> forest;
        
        if( !rm(root) )
            forest.push_back( root );
        dfs( root, forest );
        
        return forest;
    }
    
    void dfs( TreeNode *cur_node, vector<TreeNode*> &forest ){
        TreeNode *lhs, *rhs;
        lhs = cur_node->left; rhs = cur_node->right;
        
        if( rm(cur_node) ){
            if( lhs != NULL && !rm(lhs) ){
                cout << "push" << lhs->val << endl;
                forest.push_back( lhs );
            }
            if( rhs != NULL && !rm(rhs) ){
                cout << "push" << rhs->val << endl;
                forest.push_back( rhs );
            }
        }
        
        // Update Node status
        if( lhs != NULL && rm(lhs) )
            cur_node->left = NULL;
        
        if( rhs != NULL && rm(rhs) )
            cur_node->right = NULL;
        
        if( lhs != NULL )
            dfs( lhs, forest);
        if( rhs != NULL )
            dfs( rhs, forest);
        
        if( rm(cur_node) )
            delete cur_node;
    }
    
    bool rm( TreeNode *node ){
        if( rm_node.find(node->val) == rm_node.end() )
            return false;
        return true;
    }
};
