// 187. Repeated DNA Sequences
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hash_count;
        vector<string> ans;
        
        if( s.size() <= 10 ) return ans;
        
        const int M = 1 << 20;
        int val = 0;
        for(int i = 0; i < 10; i++){
            val <<= 2;
            val += cval[s[i]];
        }
        
        hash_count[val]++;
        for(int i = 10; i < s.size(); i++){
            val <<= 2;
            val += cval[s[i]];
            val %= M;
            hash_count[val]++;
        }
        
        for(auto &p: hash_count)
            if( p.second >= 2 ) ans.push_back( recover(p.first) );
        
        return ans;
    }
    
    string recover(int val){
        string s;
        for(int i = 0; i < 10; i++){
            s += invcval[val%4];
            val >>= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    unordered_map<char, int> cval{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    unordered_map<int, char> invcval{ {0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};
};
