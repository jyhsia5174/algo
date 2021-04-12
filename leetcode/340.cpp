// 340. Longest Substring with At Most K Distinct Characters
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        for(int i = 0; i < 256; i++)
            count[i] = 0;
        
        int l = 0, r = 0, L = 0;
        
        while( r < s.size() ){
            if( unique <= k ){
                L = max(L, r - l);
                add(s[r]);
                r++;
            }
            else{
                remove(s[l]);
                l++;
            }
        }
        
        if( unique <= k ) L = max( L, r - l );
        
        return L;
    }
private:
    int count[256];
    int unique = 0;
    
    void add(const char &c ){
        int cid = c;
        if( count[cid] == 0 )
            unique++;
        count[cid]++;
    }
    
    void remove(const char &c ){
        int cid = c;
        count[cid]--;
        if( count[cid] == 0 )
            unique--;
    }
};
