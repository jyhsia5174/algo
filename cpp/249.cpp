// 249. Group Shifted Strings
typedef long long int lli;
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for(auto &s: strings)
            insert(s);
        
        vector<vector<string>> ans;
        for(auto &hash_entity: hash_table){
            for(auto &list: hash_entity.second)
                ans.push_back( list.second );
        }
        
        return ans;
    }
    
    unordered_map<lli, vector<pair<vector<int>, vector<string>>>> hash_table;
    
    void insert(string &s){
        vector<int> tmp;
        for(int i = 0; i < s.size(); i++){
            int next_i = ( i + 1 ) % s.size();
            tmp.push_back( minus( s[i], s[next_i] ) );
        }
        
        lli hash_val = hash(tmp);
        
        if( hash_table[hash_val].empty() ){
            hash_table[hash_val].push_back( {tmp, vector<string>{s} } );
            return;
        }
        
        bool is_same = false;
        for(auto &pp: hash_table[hash_val]){
            auto &type = pp.first;
            auto &group = pp.second;
            
            if( tmp == type ){
                is_same = true;
                group.push_back(s);
                break;
            }
        }
            
        if( !is_same ) 
            hash_table[hash_val].push_back( {tmp, vector<string>{s} } );
    }
    
    int minus( char a, char b ){
        int result = b - a;
        if( result >= 0 ) return result;
        return 26 + result;
    }
    
    lli hash(vector<int> &A){
        lli mode = 1000000000 + 7;
        lli sum = 0;
        for(auto &a: A){
            sum = (sum * 26) % mode;
            sum += a;
        }
        return sum;
    }
};
