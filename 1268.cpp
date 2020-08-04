// 1268. Search Suggestions System
class node{
public:
    string s;
    node *ch[26];
    
    node(){
        for(int i = 0; i < 26; i++)
            ch[i] = NULL;
    }
   
    vector<node*> top3;
    
    void push(node* n){
        if( top3.size() < 3 ){
            top3.push_back(n);
        }
        else{
            node *dummy = n;
            for(int i = 0; i < top3.size(); i++){
                if( top3[i]->s > dummy->s )
                    swap(top3[i], dummy);
            }
        }
    }
};

class tri{
public:
    tri(){
        root = new node;
    }
    
    void insert(const string &s){
        insert_from_node(root, s, 0);
    }
    
    vector<vector<string>> search(const string &s){
        vector<vector<string>> res;
        
        int idx = 0;
        node *head = root;
        while( head != NULL && idx < s.size() ){
            int c = s[idx] - 'a';
            if( head->ch[c] == NULL )
                break;
            head = head->ch[c];
            res.push_back( vector<string>() );
            for(auto &n: head->top3){
                res[res.size()-1].push_back(n->s);
                sort(res[res.size()-1].begin(), res[res.size()-1].end());
            }
            idx++;
        }
        
        while( idx < s.size() ){
            res.push_back( vector<string>() );
            idx++;
        }
        
        return res;
    }
private:
    node *root;
    
    node* insert_from_node(node *n, const string &s, int idx){
        if( s.size() == idx ){
            n->s = s;
            n->push(n);
            return n;
        }
        
        int c = s[idx] - 'a';
        if( n->ch[c] == NULL )
            n->ch[c] = new node;
        node *final_node = insert_from_node(n->ch[c], s, idx+1);
        n->push(final_node);
        return final_node;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        tri mytri;
        for(auto &s: products)
            mytri.insert(s);
        
        return  mytri.search(searchWord);
    }
};
