// 987. Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if( root == NULL ) return ans;
        
        dfs(root, 0, 0);
        
        for(auto &p: M){
            sort( p.second.begin(), p.second.end() );
            vector<int> tmp;
            for(auto &val: p.second)
                tmp.push_back(val.second);
            ans.push_back( tmp );
        }
        
        return ans;
    }
    
    void dfs(TreeNode* n, int x, int y){
        if( n == NULL ) return;
        
        M[x].push_back({y,n->val});
        dfs(n->left, x-1, y+1);
        dfs(n->right, x+1, y+1);
    }
    
private:
    map<int, vector<pair<int, int>>> M;
};
