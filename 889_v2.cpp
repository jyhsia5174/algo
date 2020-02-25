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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return built( pre, post);
    }
    
    TreeNode* built( vector<int>& pre, vector<int>& post ){
        TreeNode* root = new TreeNode(pre[preIndex++]);
        
        if( root->val != post[postIndex] )
            root->left = built( pre, post);
        
        if( root->val != post[postIndex] )
            root->right = built( pre, post);
        
        postIndex++;
        return root;
    }
private:
    int preIndex = 0, postIndex = 0;
};
