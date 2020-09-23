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
        return built( pre, 0, pre.size(), post, 0, post.size() );
    }
    
    TreeNode* built( vector<int>& pre, int ia, int ja, vector<int>& post, int ib, int jb){
        
        TreeNode* node = new TreeNode(pre[ia]);
        
        if( ja - ia == 1 || jb - ib == 1 )
            return node;
        
        int l_val = pre[ia+1];
        int r_val = post[jb-2];
        
        if( l_val == r_val ){
            node->left = built(pre, ia+1, ja, post, ib, jb-1 );
            return node;
        }
        
        int ma = ja-1;
        for(; ma >= ia; ma--){
            if( pre[ma] == r_val )
                break;
        }
        
        int mb = ib;
        for(; mb < jb ; mb++){
            if(post[mb] == l_val)
                break;
        }
        
        node->left = built(pre, ia+1, ma, post, ib, mb+1);
        node->right = built(pre, ma, ja, post, mb+1, jb-1);
        return node;
    }
};
