class Solution {
public:
    string reorganizeString(string S) {
        int counts[26];
        int N = S.size();
        memset( counts, 0, sizeof(counts));
        
        for(int i = 0; i < S.size(); i++)
            counts[ S[i] - 'a'] += 100;
        for(int i = 0; i < 26; i++)
            counts[i] += i;
        
        sort( counts, counts + 26 );
        
        string ans;
        ans.resize( S.size() );
        int k = 1;
        for(int i = 0; i < 26; i++){
            int cnt = counts[i] / 100;
            char c = 'a' + (counts[i] % 100 );
            if( cnt > (N+1)/2 )
                return "";
            
            for(int j = 0; j < cnt; j++){
                if( k >= N ) k = 0;
                ans[k] = c;
                k += 2;
            }
        }
        
        return ans;
    }
};
