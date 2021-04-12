/*
95. Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> V(n, 0);
        iota(V.begin(), V.end(), 0);
        
        return helper(V, 0, n);
    }
    
    
    vector<TreeNode*> helper(const vector<int> &V, int l, int r){
        if( l == r )
            return vector<TreeNode*> {nullptr};
        
        vector<TreeNode*> res;
        for(int i = l; i < r; i++){
            vector<TreeNode*> leftT = helper(V, l, i);
            vector<TreeNode*> rightT = helper(V, i+1, r);
            
            for(auto &lt: leftT)
                for(auto &rt: rightT){
                    TreeNode* root = new TreeNode(V[i] + 1);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
        }
        
        return res;
    }
};
