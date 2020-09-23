// Count of Smaller Numbers After Self
struct Node{
    int val;
    Node *left, *right;
    int h;
    int sz;
    
    Node(int x): val(x), left(NULL), right(NULL), h(1), sz(1){};
};

class Tree{
public:
    void insert( int a ){
        root = add_node( a, root, true);
    }
    
    int count( int val ){
        return count_from_root(root, val);
    }
    
    void destroy(){
        destroy_from_root(root);
    }
    
private:
    Node *root = NULL;
    
    void destroy_from_root(Node *n){
        Node *l = n->left, *r = n->right;
        
        if( l != NULL )
            destroy_from_root( l );
        if( r != NULL )
            destroy_from_root( r );
        
        delete n;
    }
    
    int count_from_root(Node *root, int val){
        if( root == NULL )
            return 0;
        
        if( root->val >= val ){
            return count_from_root(root->left, val);
        }
        else{
            if( root->right == NULL )
                return root->sz;
            else
                return (root->sz - root->right->sz) + count_from_root(root->right, val);
        }
    }
    
    
    Node* add_node( int a, Node *n, bool is_r_child){
        if( n == NULL ){
            return new Node(a);
        }
        
        if( a > n->val )
            n->right = add_node( a, n->right, true);
        else
            n->left = add_node( a, n->left, false);
        update( n );
        
        int l_h, r_h;
        if( n->left == NULL )
            l_h = 0;
        else 
            l_h = n->left->h;
            
        if( n->right == NULL )
            r_h = 0;
        else 
            r_h = n->right->h;
            
        if( l_h - r_h == 2){
            assert(n->left != NULL);
            n = r_rotate( n );
        }
        else if( l_h - r_h == -2)
            n = l_rotate( n );
        
        if( n->left == NULL )
            l_h = 0;
        else 
            l_h = n->left->h;
            
        if( n->right == NULL )
            r_h = 0;
        else 
            r_h = n->right->h;
        
        if( is_r_child && l_h > r_h ){
            assert(n->left != NULL);
            n = r_rotate( n );
        }
        else if( !is_r_child && l_h < r_h )
            n = l_rotate( n );
        
        return n;
    }
    
    void update( Node* n){
        if( n->right == NULL && n->left == NULL ){
            n->h = 1;
            n->sz = 1;
        }
        else if( n->left == NULL ){
            n->h = n->right->h + 1;
            n->sz = n->right->sz + 1;
        }
        else if( n->right == NULL ){
            n->h = n->left->h + 1;
            n->sz = n->left->sz + 1;
        }
        else{
            n->h = max( n->left->h, n->right->h ) + 1;
            n->sz = n->left->sz + n->right->sz + 1;
        }
    }
    
    Node* r_rotate( Node* top_org ){
        Node *top_new = top_org->left;
        
        assert(top_new != NULL);
        Node *tmp = top_new->right;
        top_new->right = top_org;
        top_org->left = tmp;
        
        update( top_org );
        update( top_new );
        return top_new;
    }
    
    Node* l_rotate( Node* top_org ){
        Node *top_new = top_org->right;
        
        Node *tmp = top_new->left;
        top_new->left = top_org;
        top_org->right = tmp;
        
        update( top_org );
        update( top_new );
        return top_new;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        
        Tree s;
        vector<int> count;
        if( N == 0 )
            return count;
        count.resize(N, 0);
        
        s.insert(nums[N-1]);
        for(int i = N - 2; i >= 0; i--){
            count[i] = s.count(nums[i]);
            s.insert(nums[i]);
        }
        
        s.destroy();
        return count;
    }
};
