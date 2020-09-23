// 126. Word Ladder II
class Solution {
public:
    vector<vector<string>> findLadders(string st, string ed, vector<string>& wordList) {
        unordered_set<string> S(wordList.begin(), wordList.end());
        unordered_map<string, vector<vector<string>>> path;
        
        queue<string> Q;
        Q.push(st);
        path[st] = vector<vector<string>>{vector<string>{st}};
        while( !Q.empty() ){
            queue<string> tmp;
            while( !Q.empty() ){
                const string s = Q.front();
                Q.pop();
                for(int i = 0; i < s.size(); i++){
                    string s_cp = s;
                    for(int j = 0; j < 26; j++){
                        if( s[i] - 'a' == j )
                            continue;
                        s_cp[i] = j + 'a';
                        if( S.count(s_cp) ){
                            vector<vector<string>> &path_s = path[s];
                            if( path.count(s_cp) == 0 ||
                              (path.count(s_cp) == 1 
                               && path[s_cp][0].size() == path_s[0].size()+1)
                              ){
                                for(auto v: path_s){
                                    v.push_back(s_cp);
                                    path[s_cp].push_back(v);
                                }
                                
                                if( path[s_cp].size() == path_s.size() )
                                    tmp.push(s_cp);
                            }
                        }
                    }
                }
            }
            
            if( path.count(ed) )
                return path[ed];
            swap( Q, tmp );
        }
        
        if( path.count(ed) )
            return path[ed];
        return vector<vector<string>>();
    }
};
