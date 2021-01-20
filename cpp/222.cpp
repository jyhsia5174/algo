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
    int countNodes(TreeNode* root) {
        if( root == nullptr )
            return 0;
        
        // get max level
        int L = level(root);
        int res = 0;
        TreeNode* curNode = root;
        while( L >= 0 ){
            if( level(curNode->right) + 1 == L ){
                res += 1 << L;
                curNode = curNode->right;
            }
            else{
                res += 1 << (L-1);
                curNode = curNode->left;
            }
            L--;
        }
        
        return res;
    }
    
    int level(TreeNode* node){
        int L = -1;
        while( node != nullptr ){
            L++;
            node = node->left;
        }
        return L;
    }
};


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
    int countNodes(TreeNode* root) {
        
        int size = 0;
        TreeNode* c_node = root;
        while( c_node != NULL ){
            if( c_node->left == NULL ){
                size += 1;
                break;
            }
            
            int d_max = get_d_max( c_node->left );
            int d_min = get_d_min( c_node->left );
            
            if( d_max == d_min ){
                size += 1 << (d_min + 1);
                c_node = c_node->right;
            }
            else{
                size += 1 << (d_min + 1);
                c_node = c_node->left;
            }
        }
        
        return size;
    }
    
    int get_d_max( TreeNode* root ){
        TreeNode *c_node = root;
        int d = -1;
        while( c_node != NULL ){
            c_node = c_node->left;
            d++;
        }
        
        return d;
    }
    
    int get_d_min( TreeNode* root ){
        TreeNode *c_node = root;
        int d = -1;
        while( c_node != NULL ){
            c_node = c_node->right;
            d++;
        }
        
        return d;
    }
};
