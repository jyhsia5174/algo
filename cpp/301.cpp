// 301. Remove Invalid Parentheses
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        N = s.size();
        mask.resize(N, 1);
        
        int l_count = 0;
        int r_count = 0;
        for(int i = 0; i < N; i++){
            if( s[i] == '(' )
                l_count++; 
            else if( s[i] == ')' ){
                if( l_count == 0 )
                    r_count++;
                else
                    l_count--;
            }
        }
        
        remove(s, 0, l_count, r_count);
        
        vector<string> all(results.begin(), results.end());
        if(all.size() == 0) all.push_back("");
        return all;
    }
    
    void remove(string s, int idx, int l_count, int r_count){
        cout << l_count << " " << r_count << endl;
        if( (l_count == 0 && r_count == 0) || s.size() == idx ){
            if( valid(s) )
                results.insert( generate(s) );
            return;
        }
        
        if( !check( s, idx ) ) return;
        
        for(int i = idx; i < s.size() - (l_count + r_count) + 1; i++){
            if( s[i] == '(' && l_count > 0 ){
                mask[i] = 0;
                remove(s, i+1, l_count-1, r_count);
                mask[i] = 1;
            }
            else if( s[i] == ')' && r_count > 0 ){
                mask[i] = 0;
                remove(s, i+1, l_count, r_count-1);
                mask[i] = 1;
            }
            else{
                // do nothing
            }
        }
    }
    
    bool check(string &s, int idx){
        int stack = 0;
        for(int i = 0; i < idx; i++){
            if( mask[i] == 0 ) continue;
            if( s[i] == '(' )
                stack++;
            else if(s[i] == ')')
                stack--;
            if( stack < 0 ) return false;
        }
        return true;
    }
    
    bool valid(string &s){
        int stack = 0;
        for(int i = 0; i < N; i++){
            if( mask[i] == 0 ) continue;
            if( stack < 0 ) return false;
            if( s[i] == '(' )
                stack++;
            else if(s[i] == ')')
                stack--;
        }
        
        if( stack != 0 ) return false;
        return true;
    }
    
    string generate(string s){
        string res;
        for(int i = 0; i < N; i++){
            if( mask[i] == 1 )
                res += s[i]; 
        }
        return res;
    }
    
private:
    set<string> results;
    vector<int> mask;
    int N;
};
