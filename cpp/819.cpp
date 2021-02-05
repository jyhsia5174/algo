// 819. Most Common Word


class Solution {
public:
    string mostCommonWord(string P, vector<string>& banned) {
        unordered_set<string> B(banned.begin(), banned.end());
        unordered_map<string, int> count;
        
        for(int i = 0; i < P.size(); i++)
            P[i] = isalpha(P[i])? tolower(P[i]) : ' ';
        
        string res;
        int maxCnt = 0;
        istringstream iss(P);
        string w;
        while( iss >> w ){
            if( B.find(w) == B.end() ){
                count[w] ++;
                if( count[w] > maxCnt ){
                    res = w;
                    maxCnt = count[w];
                }
            }
        }
        
        return res;
    }
};


// old version

class Solution {
public:
    string mostCommonWord(string P, vector<string>& banned) {
        unordered_set<string> B(banned.begin(), banned.end());
        unordered_map<string, int> count;
        
        string res;
        int max_count = 0;
        string word;
        for(int i = 0; i < P.size(); i++){
            if( !isalpha(P[i]) ){
                if(word.size() > 0 && B.count(word) == 0) 
                    count[word]++;
                if( max_count < count[word] ){
                    res = word;
                    max_count = count[word];
                }
                word = "";
            }
            else{
                word += tolower(P[i]);
            }
        }
        
        if(word.size() > 0 && B.count(word) == 0){
                count[word]++;
            if( max_count < count[word] ){
                    res = word;
                    max_count = count[word];
                }
            word = "";
        }
        
        return res;
    }
};


// trie version

/*
819. Most Common Word
*/

class node{
public:
    node* ch[26];
    bool matched;
    node(){
        for(int i = 0; i < 26; i++)
            ch[i] = nullptr;
        matched = false;
    }
};

class Solution {
public:
    string mostCommonWord(string P, vector<string>& banned) {
        // build char tree
        root = new node();
        init_trie(banned);
        
        int i = 0;
        while( i < P.size() ){
            string s = get_word(P, i);
            if( s.size() == 0 )
                continue;
            update_freq( s );
        }
        
        string res;
        int cnt = 0;
        for(auto &key_val: freq){
            if( key_val.second > cnt ){
                res = key_val.first;
                cnt = key_val.second;
            }
        }
        
        return res;
    }
    
    bool isBanned(const string &s){
        node *head = root;
        bool isBanned = false;
        for(auto &c: s){
            int val = c - 'a';
            if( head->ch[val] == nullptr )
                return false;
            else
                head = head->ch[val];
        }
        
        return head->matched;
    } 
    
    void update_freq(const string &s){
        if( !isBanned(s) ){
            freq[s]++;
        }
    }
    
    string get_word(const string &P, int &i){
        // skip pucn and white space
        while(i < P.size() &&  punc.find(P[i]) != punc.end())
            i++;
        
        string res = "";
        while(i < P.size() && punc.find(P[i]) == punc.end()){
            res.push_back(tolower(P[i]));
            i++;
        }
        
        return res;
    }
    
    void init_trie(const vector<string> &banned){
        for(auto &s: banned){
            node *head = root;
            for(auto &c: s){
                int val = c - 'a';
                if( head->ch[val] == nullptr )
                    head->ch[val] = new node();
                head = head->ch[val];
            }
            head->matched = true;
        }
    }
    
private:
    node *root;
    unordered_map<string, int> freq;
    unordered_set<char> punc{'!', '?', '\'', ',', ';', '.', ' '};
};
