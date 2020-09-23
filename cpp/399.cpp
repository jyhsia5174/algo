// 399. Evaluate Division
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

// 399. Evaluate Division
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        if(values.size() == 0) return result;
        
        // hash string to id
        unordered_map<string, int> hash;
        int count = 0;
        for(auto &s: equations){
            string &s1 = s[0];
            string &s2 = s[1];
            
            if( !hash.count(s1) ){
                hash[s1] = count;
                count++;
            }
            
            if( !hash.count(s2) ){
                hash[s2] = count;
                count++;
            }
        }
        
        // edge 0: {id, cost}
        E.resize(count);
        for(int i = 0; i < values.size(); i++){
            string &s1 = equations[i][0];
            string &s2 = equations[i][1];
            double &val = values[i];
            int hash1 = hash[s1];
            int hash2 = hash[s2];
            
            E[hash1].push_back( {hash2, val} );
            E[hash2].push_back( {hash1, 1.0/val} );
            
            ans[ {hash1, hash2} ] = val;
            ans[ {hash2, hash1} ] = 1.0/val;
        }
        
        visited.resize(count, false);
        for(auto &s: queries){
            string &s1 = s[0];
            string &s2 = s[1];
            if( !hash.count(s1) || !hash.count(s2) ){
                result.push_back(-1);
                continue;
            }
            
            int hash1 = hash[s1];
            int hash2 = hash[s2];
            
            if( hash1 == hash2 ){
                result.push_back(1);
                continue;
            }
            
            fill(visited.begin(), visited.end(), false);
            result.push_back(dfs(hash1, hash2));
        }
        
        return result;
    }
private:
    unordered_map<pair<int, int>, double, hash_pair> ans;
    vector<vector<pair<int, double>>> E;
    vector<bool> visited;
    double dfs( int cur_idx, int target_idx ){
        if( cur_idx == target_idx ) return 1;
        pair<int, int> pp{cur_idx, target_idx};
        if( ans.count(pp) ) return ans[pp];
        
        double res = -1;
        for(auto &next: E[cur_idx]){
            if( visited[next.first] ) continue;
            visited[next.first] = true;
            res = dfs( next.first, target_idx );
            if( res != -1 ){
                ans[pp] = res * next.second;
                return ans[pp];
                //return res * next.second;
            }
        }
        
        return -1;
    }
};
