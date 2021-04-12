// 212. Word Search II
class TrieNode{
public:
    TrieNode *child[26];
    bool isWord = false;
    
    TrieNode(){
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode root;
        for(auto &w: words)
            insert(&root, w);
        
        unordered_set<string> res;
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited( m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                backtracing("", &root, res, board, visited, i, j);
        
        vector<string> ans;
        for(auto &w: res)
            ans.push_back(w);
        
        return ans;
    }
    
    void backtracing(string s, TrieNode *node, unordered_set<string> &res, const vector<vector<char>>& B, vector<vector<bool>>& visited, int x, int y){
        if( node == nullptr )
            return;
        
        visited[x][y] = true;
        
        int c = B[x][y] - 'a';
        if( node->child[c] != nullptr ){
            s = s + B[x][y];
            if( node->child[c]->isWord )
                res.insert(s);
            
            for(int d = 0; d < 4; d++){
                int xx = x + dx[d], yy = y + dy[d];
                if( xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy] )
                    backtracing(s, node->child[c], res, B, visited, xx, yy);
            }
        }
        
        visited[x][y] = false;
    }
    
    void insert(TrieNode *node, const string &w){
        for(int i = 0; i < w.size(); i++){
            int c = w[i] - 'a';
            
            if( node->child[c] == nullptr )
                node->child[c] = new TrieNode();
            
            node = node->child[c];
        }
        
        node->isWord = true;
    }
    
private:
    int m, n;
    vector<int> dx{0, 0, -1, 1};
    vector<int> dy{1, -1, 0, 0};
};

// 212. Word Search II
struct node{
public:
    string word;
    node *ch[26], *parent;
    int count;
    node(){
        count = 0;
        word = "";
        parent = NULL;
        for(int i = 0; i < 26; i++)
            ch[i] = NULL;
    }
};

class tri{
public:
    tri(){
        root = new node;
        reset_head();
    }
    
    void reset_head(){
        head = root;
    }
    
    void insert(const string &s){
        reset_head();
        insert_from_head(s, 0);
    }
    
    bool exist(const char &c){
        return head->ch[c-'a'] != NULL;
    }
    
    void next(const char &c){
        head = head->ch[c-'a'];
    }
    
    void update_then_back(){
        node *parent = head->parent;
        head = parent;
    }
    
    bool found(){
        return head->word.size() > 0;
    }
    
    string get_word(){
        kill_node_with_no_ch = true;
        string res = head->word;
        head->word = "";
        return res;
    }
private:
    node *head, *root;
    bool kill_node_with_no_ch = false;
    
    void insert_from_head(const string &s, int idx){
        if( s.size() == idx ){
            head->word = s;
            return;
        }
        
        if( !exist(s[idx]) )
            add_node(s[idx]);
        next(s[idx]);
        insert_from_head(s, idx+1);
    }
    
    void add_node(const char &c){
        head->ch[c-'a'] = new node;
        head->ch[c-'a']->parent = head;
        head->count ++;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        N = board.size();
        M = board[0].size();
        for(auto &s: words)
            T.insert(s);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                T.reset_head();
                if( T.exist(board[i][j]) ){
                    backtracing(i, j, board);
                }
            }
        }
        
        return res;
    }
    
    void backtracing(int x, int y, vector<vector<char>> &board){
        T.next(board[x][y]);
        if(T.found()) res.push_back(T.get_word());
        char char_cache = board[x][y];
        board[x][y] = '#';
        
        int xx, yy;
        for(int d = 0; d < 4; d++){
            xx = x + dx[d];
            yy = y + dy[d];
            if( xx >= 0 && xx < N && yy >= 0 && yy < M 
              && board[xx][yy] != '#' ){
                if(T.exist(board[xx][yy]))
                    backtracing(xx, yy, board);
            }
        }
        
        board[x][y] = char_cache;
        T.update_then_back();
    }
    
    
private:
    tri T;
    int N, M;
    vector<string> res;
    vector<int> dx {0, 0, 1, -1};
    vector<int> dy {1, -1, 0, 0};
};
