class Solution {
public:
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> hash_table;
        for(int i = 0; i < words.size(); i++){
            hash_table[ string(words[i].rbegin(), words[i].rend()) ] = i;
        }
                
        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); i++){
            string &s = words[i];
            int N = s.size();
            for( int k = 1; k < N; k++ ){
                string a = s.substr(0, k), b = s.substr(k, N-(k));
                
                if( is_pal(a) && hash_table.find(b) != hash_table.end() ){
                    int j = hash_table[b];
                    if( i != j )
                        ans.push_back( {j, i} );
                }
                
                if( is_pal(b) && hash_table.find(a) != hash_table.end() ){
                    int j = hash_table[a];
                    if( i != j )
                        ans.push_back( {i, j} );
                }
            }
            
            if( hash_table.find(s) != hash_table.end() ){
                int j = hash_table[s];
                if( i != j )
                    ans.push_back({ i, j });
            }
            
            if( hash_table.find("") != hash_table.end() ){
                int j = hash_table[""];
                if( i != j && is_pal( s ) )
                    ans.push_back({ i, j });
            }
            
            if( s == "" ){
                for(int j = 0; j < words.size(); j++){
                    if( i != j &&  is_pal( words[j] )  )
                        ans.push_back( {i, j} );
                }
            }
        }

        return ans;
    }
    
    bool is_pal( string s ){
        if( s.size() == 0 )
            return true;
        
        int N = s.size();
        for(int i = 0; i < N / 2; i++)
            if( s[i] != s[N-1-i] )
                return false;
        return true;
    }
};
