// 340. Longest Substring with At Most K Distinct Characters
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if( k == 0 ) return 0;
        if( s.size() <= k ) return s.size();
        for(int i = 0; i < 300; i++)
            count[i] = 0;
        
        int l = 0, r = 0;
        while( r < s.size() && unique <= k ){
            add( s[r] );
            r++;
        }
        
        int L;
        if( unique <= k )
            L = r - l;
        else
            L = r - l - 1;
        
        while( r < s.size() ){
            while( unique > k ){
                remove(s[l]);
                l++;
            }
            
            while( r < s.size() && unique <= k ){
                add( s[r] );
                r++;
            }
            
            int L_tmp;
            if( unique <= k )
                L_tmp = r - l;
            else
                L_tmp = r - l - 1;
            L = max( L, L_tmp );
        }
        
        return L;
    }
private:
    int count[300];
    int unique = 0;
    
    void add(const char &c ){
        int cid = (unsigned char) c;
        if( count[cid] == 0 )
            unique++;
        count[cid]++;
    }
    
    void remove(const char &c ){
        int cid = (unsigned char) c;
        count[cid]--;
        if( count[cid] == 0 )
            unique--;
    }
};
