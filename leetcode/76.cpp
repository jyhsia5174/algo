/*
76. Minimum Window Substring
Runtime: 24 ms, faster than 62.98% of C++ online submissions for Minimum Window Substring.
Memory Usage: 7.8 MB, less than 84.76% of C++ online submissions for Minimum Window Substring.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int st_i = 0, ed_i = 0;
        int len = 2<<29;
        
        int m = s.size();
        
        unordered_map< char, int > sm;
        unordered_map< char, int > tm;
        for(int i = 0; i < t.size(); i++)
            tm[t[i]]++;
        
        int number_matched = 0;
        int head = 0, tail = 0;
        while(head < m && tail <= m){
            if( number_matched == tm.size() ){
                // advance head [head, tail) --> head, head+1, ..., head + k , tail
                // tail - head == interval length
                char c = s[head];
                sm[c]--;
                if( tm.find(c) != tm.end() && sm[c] < tm[c] ){
                    // [head, tail) is minimal with tail fixed
                    number_matched--;
                    // update solution
                    if( len > tail - head ){
                        st_i = head;
                        ed_i = tail;
                        len = tail - head;
                    }
                }
                head++;
            }
            else{
                // advance tail
                if( tail >= m )
                    break;
                char c = s[tail];
                sm[c]++;
                if( tm.find(c) != tm.end() && sm[c] == tm[c] )
                    number_matched++;
                tail++;
            }
        }
        
        return s.substr( st_i, ed_i - st_i ); // provided exists
    }
};

// Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        for(int i = 0; i < 256; i++)
            Tcount[i] = count[i] = 0;
        
        for(int i = 0; i < t.size(); i++){
            Tcount[t[i]] ++;
        }
        
        int l = 0, r = 0;
        int minL = 1 << 30;
        int ll, rr;
        while(true){
            if(valid()){
                if( r - l < minL ){
                    ll = l;
                    rr = r;
                    minL = r - l;
                }
                
                count[s[l]] --;
                l++;
            }
            else{
                if( r == s.size() )
                    break;
                count[s[r]] ++;
                r++;
            }
        }
        
        if( minL != 1 << 30 )
            return s.substr(ll, minL);
        return "";
    }
private:
    int Tcount[256], count[256];
    
    bool valid(){
        for(int i = 0; i < 256; i++)
            if( count[i] < Tcount[i] )
                return false;
        return true;
    }
};
