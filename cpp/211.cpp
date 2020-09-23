// 211. Add and Search Word - Data structure design
class Node{
public:
    int count = 0;
    Node *ch[26];
    Node (){
        for(int i = 0; i < 26; i++)
            ch[i] = NULL;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(root, word, 0 );
    }
    
    void insert(Node *n, string &w, int i){
        if( i == w.size() ){
            n->count++;
            return;
        }
        
        if(w[i] == '.'){
            for(int i = 0; i < 26; i++){
                if( n->ch[i] == NULL )
                    n->ch[i] = new Node;
        
                insert(n->ch[i], w, i+1);    
            }
        }
        else{
            int chash = w[i] - 'a';
            if( n->ch[chash] == NULL )
                n->ch[chash] = new Node;
        
            insert(n->ch[chash], w, i+1);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(root, word, 0);
    }
    
    bool find( Node *n, string &w, int ii ){
        if( ii == w.size() ){
            if( n->count == 0 ) return false;
            return true;
        }
        
        if( w[ii] == '.'){
            for(int i = 0; i < 26; i++)
                if( n->ch[i] != NULL && find(n->ch[i], w, ii+1) )
                    return true;
            return false;
        }
        else{
            int chash = w[ii] - 'a';
            if( n->ch[chash] == NULL ) return false;
            return find( n->ch[chash], w, ii+1 );
        }
    }
private:
    Node *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
