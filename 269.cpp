// 269. Alien Dictionary
class Solution {
public:
    string alienOrder(vector<string>& words) {
        queue<queue<string *>> Q, Q_tmp;
        
        for(int i = 0; i < 26; i++)
            p_count[i] = -1;
        
        for(auto &s: words)
            for(auto &c: s)
                p_count[c-'a'] = 0;
        
        queue<string*> w_que;
        for(int i = 0; i < words.size(); i++)
            w_que.push( &(words[i]) );
        Q.push( w_que );
        
        int idx = 0;
        while( !Q.empty() ){
            while( !Q.empty() ){
                queue<string*> q = Q.front();
                Q.pop();
                if( q.size() <= 1 ) continue;
                
                string rank;
                int size;
                rank += (*(q.front()))[idx];
                queue<string*> tmp;
                while( !q.empty() ){
                    if( rank[rank.size()-1] != (*(q.front()))[idx] ){
                        Q_tmp.push( tmp );
                        queue<string*> empty_q; swap( empty_q, tmp );
                        rank += (*(q.front()))[idx];
                    }
                    
                    if( idx + 1 < (*(q.front())).size() )
                        tmp.push(q.front());
                    if( idx + 1 ==  (*(q.front())).size() && tmp.size() > 0)
                        return "";
                    q.pop();
                }
                if( tmp.size() > 0 ) Q_tmp.push( tmp );
                if( rank.size() >= 2 ) build_graph( rank );
            }
            idx++;
            swap( Q, Q_tmp );
        }
        
        return parse_graph();
    }
    
    void build_graph(string &tmp){
        // input non-empty string
        for(int i = 0; i < tmp.size(); i++){
            for(int j = i+1; j < tmp.size(); j++){
                int a = tmp[i] - 'a';
                int b = tmp[j] - 'a';
                E[a].push_back(b);
                p_count[b] += 1;
            }
        }
    }
    
    string parse_graph(){
        for(int i = 0; i < 26; i++)
            if( p_count[i] != -1 ) char_count++;
        
        string ans;
        while( ans.size() < char_count ){
            int root = -1;
            for(int i = 0; i < 26; i++){
                if( p_count[i] == 0 ){
                    root = i;
                    break;
                }
            }
            
            if( root == -1 ) return "";
            p_count[root] = -1;
            
            for(auto &child: E[root])
                p_count[child]--;
            ans += 'a' + root;
        }
        
        return ans;
    }
private:
    vector<int> E[26];
    bool visited[26];
    int p_count[26];
    string longest_cache[26];
    int char_count;
    unordered_set<string> rank_list;
};
