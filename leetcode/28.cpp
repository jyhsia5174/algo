/*
28. Implement strStr()
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
Memory Usage: 7 MB, less than 68.53% of C++ online submissions for Implement strStr().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.size() == 0 )
            return 0;
        
        if( haystack.size() < needle.size() )
            return -1;
        
        const int n = needle.size();
        vector<int> jump(n, -1);
        int k = -1;
        for(int i = 1; i < n; i++){
            while( k != -1 && needle[i] != needle[k+1] )
                k = jump[k];
            
            if( needle[i] == needle[k+1] )
                k = k+1;
            jump[i] = k;  
        }

        k = -1;
        for(int i = 0; i < haystack.size(); i++){
            while( k != -1 && haystack[i] != needle[k+1] )
                k = jump[k];
            
            if(haystack[i] == needle[k+1])
                k++;
            
            if( k+1 == needle.size() )
                return i - needle.size() + 1;
        }
        
        return -1;
    }
};
