/*
833. Find And Replace in String
*/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<int> ref(n, 0);
        iota(ref.begin(), ref.end(), 0);
        sort(ref.begin(), ref.end(), [indexes](const int &i, const int &j){
           return indexes[i] < indexes[j]; 
        });
        
        string res = S.substr(0, indexes[ref[0]] );
        for(int i = 0; i < ref.size(); i++){
            int j = indexes[ref[i]];
            string &src = sources[ref[i]];
            string &targ = targets[ref[i]];
            
            if( S.substr(j, src.size()) == src )
                res += targ;
            else
                res += S.substr(j, src.size());
            
            if( i+1 < ref.size() )
                res += S.substr(j+src.size(), indexes[ref[i+1]] - (j+src.size()) );
            else
                res += S.substr(j+src.size(), S.size() - (j+src.size()) );
        }
        
        return res;
    }
};

/*
833. Find And Replace in String
*/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<int> ref(n, 0);
        iota(ref.begin(), ref.end(), 0);
        sort(ref.begin(), ref.end(), [indexes](const int &i, const int &j){
           return indexes[i] < indexes[j]; 
        });
        
        string res = "";
        int i = 0;
        int j = 0;
        int nextR = indexes[ref[j]];
        while( i < S.size() ){
            if( i == nextR ){
                string &src = sources[ref[j]];
                string &targ = targets[ref[j]];
                if( S.compare(i, src.size(), src) == 0){
                    res += targ;
                }
                else{
                    res += S.substr(i, src.size());
                }
                i+= src.size();
                
                j++;
                if( j < n )
                    nextR = indexes[ref[j]];
                else
                    nextR = -1;
            }
            else{
                res += S[i];
                i++;
            }
        }
        
        return res;
    }
};

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
