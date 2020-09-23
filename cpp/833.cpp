class Solution {
public:
    string findReplaceString(string S, vector<int>& idxs, vector<string>& srcs, vector<string>& Ts) {
         
        unordered_map<int, int> src_id;
        for(int i = 0; i < idxs.size(); i++)
            src_id[idxs[i]] = i;
        
        string res = "";
        for(int i = 0; i < S.size();){
            if( src_id.find(i) != src_id.end() ){
                int &id = src_id[i];
                string &s1 = srcs[id];
                string &s2 = Ts[id];
                res += replace( i, S, s1, s2 );
                i += s1.size();
            }
            else{
                res += S[i];
                i++;
            }
        }
        
        return res;
    }
    
    string replace( const int i, const string &S, const string &match, const string &target ){
        bool is_match = true;
        for(int sz = 0; sz < match.size(); sz++){
            if( S[i+sz] != match[sz] ){
                is_match = false;
                break;
            }
        }
            
        if( is_match )
            return target;
        else
            return S.substr(i, match.size());
    }
};
