//AVL tree solution

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
    
    double find_median(){
        int total_sz = root->sz;
        
        if( total_sz % 2 == 1 ){
            return find_by_rank( total_sz / 2 + 1 );
        }
        else{
            return ( find_by_rank( total_sz / 2 ) + find_by_rank( total_sz / 2 + 1) ) / 2.0 ;
        }
    }
    
    
    
private:
    Node *root = NULL;
    
    int find_by_rank(int rank){
        int acc_rank = 0;
        Node *cur_node = root;
        while( true ){
            int lsz = (cur_node->left == NULL)? 0 : cur_node->left->sz;
            int cur_node_rank = acc_rank + lsz + 1;
            if( cur_node_rank == rank ){
                return cur_node->val;
            }
            else if( cur_node_rank < rank ){
                acc_rank = cur_node_rank;
                cur_node = cur_node->right;
            }
            else{
                cur_node = cur_node->left;
            }
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
            
        if( l_h - r_h == 2)
            n = r_rotate( n );
        else if( l_h - r_h == -2)
            n = l_rotate( n );
        
        if( is_r_child && l_h > r_h )
            n = r_rotate( n );
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

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder(){}
    
    void addNum(int num) {
        mytree.insert(num);
    }
    
    double findMedian() {
        return mytree.find_median();
    }
    
private:
    Tree mytree;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
