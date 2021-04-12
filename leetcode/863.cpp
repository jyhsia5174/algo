// 863. All Nodes Distance K in Binary Tree
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs( root, target, K );
            
        return res;
    }
    
    int dfs(TreeNode* root, const TreeNode* target, int K){
        if( root == NULL )
            return -1;
        
        int ld = dfs(root->left, target, K);
        int rd = dfs(root->right, target, K);
        int d = max(ld, rd);
        if( root == target )
            d = 0;
        
        if( ld == -1 && d != -1)
            k_insert(root->left, K-d-1);
        if( rd == -1 && d != -1)
            k_insert(root->right, K-d-1);
        
        if( d == K )
            res.push_back( root->val );
        
        d = (d == -1)? -1 : d+1;
        return d;
    }
    
    void k_insert(TreeNode *root, int dist){
        if( root == NULL || dist < 0 ) return;
        if( dist == 0 ){
            res.push_back(root->val);
        }
        else{
            k_insert( root->left, dist-1 );
            k_insert( root->right, dist-1 );
        }
    }
private:
    vector<int> res;
};
