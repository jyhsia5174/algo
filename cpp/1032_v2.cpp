class Tnode{
public:
    int next[26];
    bool is_end_state;
    
    Tnode(): is_end_state(false) {
        for(int i = 0; i < 26; i++)
            next[i] = -1;
    }
};

class ac_automaton{
public:
    void built( vector<string> &S ){
        construct_trie(S);
        construct_link();
    }
    
    void move( char c ){
        int ch = c - 'a';
        while( cur_state != 0 && Trie[cur_state].next[ch] == -1 )
            cur_state = failure[cur_state];
        
        if( Trie[cur_state].next[ch] != -1 )
            cur_state = Trie[cur_state].next[ch];
        else
            cur_state = 0;
    }
    
    bool match(){
        if( Trie[cur_state].is_end_state )
            return true;
        else if( out[cur_state] != -1 )
            return true;
        return false;
    }
    
private:
    vector<Tnode> Trie;
    vector<int> failure, out;
    int cur_state = 0;
    
    void construct_trie( vector<string> &S ){
        Trie.emplace_back();
        for(auto &s: S){
            int state = 0;
            for(auto &c: s){
                int ch = c - 'a';
                if( Trie[state].next[ch] == -1 ){
                    Trie[state].next[ch] = Trie.size();
                    Trie.emplace_back();
                }
                state = Trie[state].next[ch];
            }
            
            Trie[state].is_end_state = true;
        }
    }
    
    void construct_link(){
        failure.resize( Trie.size(), 0 );
        out.resize( Trie.size(), -1 );
        
        queue<int> Q;
        for(int i = 0; i < 26; i++){
            if( Trie[0].next[i] != -1){
                Q.push( Trie[0].next[i] );
                failure[Trie[0].next[i]] = 0;
            }
        }
        
        while( !Q.empty() ){
            int state = Q.front();
            Q.pop();
            
            for(int i = 0; i < 26; i++){
                if( Trie[state].next[i] != -1 ){
                    int next_state = Trie[state].next[i];
                    int link_state = failure[state];
                    
                    while( link_state != 0 && Trie[link_state].next[i] == -1 )
                        link_state = failure[link_state];
                    
                    failure[next_state] = (Trie[link_state].next[i] == -1) ? 0 : Trie[link_state].next[i]; 
                    
                    if( Trie[failure[next_state]].is_end_state )
                        out[next_state] = failure[next_state];
                    else
                        out[next_state] = out[failure[next_state]];
                    
                    Q.push(next_state);
                }
            }
        }
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        machine.built( words );
    }
    
    bool query(char letter) {
        machine.move(letter);
        return machine.match();
    }
    
private: 
    ac_automaton machine;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
