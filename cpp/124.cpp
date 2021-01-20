// 124. Binary Tree Maximum Path Sum

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
    int maxPathSum(TreeNode* root) {
        maxSum( root );
        return res;
    }
    
    int maxSum( TreeNode* node ){
        if( node == nullptr )
            return 0;
        
        int l = maxSum( node->left );
        int r = maxSum( node->right );
        
        res = max( res, node->val );
        res = max( res, l + node->val );
        res = max( res, r + node->val );
        res = max( res, l + r + node->val );
        
        return max( node->val, max(node->val + l, node->val + r ));
    }
    
    int res = -(1<<29);
};


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
typedef long long int lli;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if( root == NULL ) return 0;
        int id = -1;
        dfs_ch(root, id);
        id = -1;
        dfs(root, 0, id);
        return ans;
    }
    
    int dfs_ch(TreeNode* n, int &id){
        if( n == NULL ) return 0;
        id++;
        int cur_id = id;
        if( cache.count(id) == 1) return cache[cur_id][0];
        
        int l = dfs_ch(n->left, id);
        int r = dfs_ch(n->right, id);
        
        vector<int> tmp{max(max(n->val + max(l, r), n->val), 0), l, r};
        cache[cur_id] = tmp;
        return cache[cur_id][0];
    }
    
    void dfs(TreeNode* n, int p_sum, int &id){
        if( n == NULL ) return;
        id++;
        
        vector<int> path{0, 0, 0};
        path[0] = p_sum; 
        path[1] = cache[id][1];
        path[2] = cache[id][2];
        
        int l_p_best = max(max(max(path[0], path[2]),0)
                           + n->val, 0);
        int r_p_best = max(max(max(path[0], path[1]),0)
                           + n->val, 0);
        
        dfs(n->left, l_p_best, id);
        dfs(n->right, r_p_best, id);
        
        for(int i = 0; i < 3; i++)
            for(int j = i+1; j < 3; j++)
                ans = max( ans,  n->val + max(path[i] + path[j], 0) );
        
        return;
    }
    
private:
    const int INF = -( 1 << 29 );
    int ans = INF;
    unordered_map<int, vector<int>> cache;
};
