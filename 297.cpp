/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string intToS( int x ){
        char c[4];
        for(int i = 3; i >= 0; i--)
            c[3-i] = (char) ( (x >> (i*8)) & 0xff );
        
        return string( c, 4);
    }
    
    int sToInt( string s){
        unsigned int res = 0;
        for(int i = 0; i < 4; i++)
            res = (res << 8) + (unsigned int) (unsigned char) s[i];
        return (int) res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(  root, res );
        return res;
    }
    
    void dfs( TreeNode* root, string &res ){
        if( root == NULL ){
            res += "####";
            return;
        }
        
        res += intToS( root->val );
        dfs( root->left, res);
        dfs( root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root = NULL;
        int i = 0;
        rdfs( root, data, i);
        return root;
    }
    
    void rdfs( TreeNode *&root, string &data, int &i){
        if( i >= data.size()  || data[i] == '#'){
            i+=4;
            return;
        }

        root = new TreeNode( sToInt( data.substr(i, 4) ) );
        i+=4;
        
        rdfs( root->left, data, i);
        rdfs( root->right, data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
