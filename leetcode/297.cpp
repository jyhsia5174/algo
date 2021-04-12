/*
297. Serialize and Deserialize Binary Tree
Runtime: 48 ms, faster than 86.35% of C++ online submissions for Serialize and Deserialize Binary Tree.
Memory Usage: 30.8 MB, less than 94.84% of C++ online submissions for Serialize and Deserialize Binary Tree.
*/

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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfs( root, res );
        return res;
    }
    
    void dfs( TreeNode* node, string &res ){
        if( node == nullptr ){
            res +="n";
            return;
        }
        
        res += encodeInt( node->val );
        dfs( node->left, res);
        dfs( node->right, res);
        
        return;
    }
    
    string encodeInt( int val ){
        string res = "     " + to_string(val);
        res = res.substr(res.size() - 5, 5);
        return res;
    }
    
    int decodeInt( const string &val ){
        int i = val.find_first_not_of( "0" );
        return stoi( val.substr( i, val.size() - i ) );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return helper(data, idx);
    }
    
    TreeNode* helper(const string &data, int &idx){
        assert( idx < data.size() );
        if( data[idx] == 'n' ){
            idx++;
            return nullptr;
        }
        
        int val = decodeInt(data.substr(idx, 5));
        idx+=5;
        TreeNode* node = new TreeNode(val);
        
        TreeNode* left = helper(data, idx);
        TreeNode* right = helper(data, idx);
        
        node->left = left;
        node->right = right;
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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
