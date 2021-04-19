class Solution {
public:
    int minLen = INT_MAX;
    string res;
    
    bool match(string abbr, string s){
        int n = abbr.size();
        int x = 0;
        for(int i = 0; i < n;){
            if( x >= s.size() ) return false;
            if( isdigit(abbr[i]) ){
                int len = 0;
                while(i < n && isdigit(abbr[i])){
                    len *= 10;
                    len += abbr[i]-'0';  // bug1: atoi
                    i++;
                }
                x += len;
            }
            else{
                if(abbr[i] != s[x]) return false; // bug4
                x++;
                i++;
            }
        }
        return x == s.size();
    }
    
    void backtrack(string pre, string rem, vector<string> &D, int sz){
        if(rem == ""){
            //cout << pre << endl;
            for(auto &s: D)
                if( match(pre, s) ) return; // bug2: (pre, D) D is not string
            if( sz <= minLen ){ // bug4: sz is customed www.
                res = pre;
                minLen = sz;
            }
        }
        
        int n = rem.size();
        for(int i = 0; i < n; i++){
            string pre1 = pre + rem.substr(0,i); // pre1 
            int sz1 = sz + i;
            for(int j = i+1; j <= n; j++){
                string pre2 = pre1 + to_string(j-i); // pre2 should not modify pre1
                int sz2 = sz1 + 1;
                if(j < n){
                    sz2 += 1;
                    pre2 += rem[j];
                }
                
                string nextrem = "";
                if( j+1 < n )
                    nextrem = rem.substr(j+1, string::npos); // should update nextrem
                
                //cout << pre2 << "\t" << nextrem << endl;
                backtrack(pre2, nextrem, D, sz2);
            }
        }
    }
    
    string minAbbreviation(string T, vector<string>& D) {
        res = T;
        minLen = T.size();
        backtrack("", T, D, 0);
        return res;
    }
};
