/*
159. Longest Substring with At Most Two Distinct Characters
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
Memory Usage: 6.7 MB, less than 97.12% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() == 0)
            return 0;
        int m[256];
        memset( m, 0, sizeof(m) );
            
        int c = 'a'; // c [0, 256)
        
        int n = s.size();
        int maxL = 0;
        int cnt = 0;
        int h = 0, t = 0;
        while( h < n && t <= n ){
            if( cnt > 2 ){
                // advance head
                unsigned int c = (unsigned int) s[h];
                m[c]--;
                if( m[c] == 0 )
                    cnt--;
                h++;
            }
            else{
                maxL = max(maxL, t - h);
                
                if( t >= n )
                    break;
                
                // advance tail
                unsigned int c = (unsigned int) s[t];
                m[c]++;
                if( m[c] == 1 )
                    cnt++;
                t++;
            }
        }
        
        return maxL;
        
    }
};
