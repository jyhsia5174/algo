// 647. Palindromic Substrings
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        if( n == 0 ) return 0;
        
        // [i-d, i+d]
        vector<int> d(2*n+1, 0);
        int center = 0, right = 0;
        for(int i = 0; i < 2*n+1; i++){
            if( i < right )
                d[i] = min(right - i, d[2*center-i]);
            while( ((i+d[i]-1)/2+1) < n && ((i-d[i])/2-1) >= 0
                  && s[(i+d[i]-1)/2+1] == s[(i-d[i])/2-1] )
                d[i] += 2;
            if( i % 2 == 1 && d[i] % 2 == 0 ) d[i]++;
            if( i + d[i] > right ){
                center = i;
                right = i + d[i];
            }
        }
        
        int ans = 0;
        for(auto &v: d)
            ans += (v+1)/2;
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        if( n == 0 ) return 0;
        
        int count = 0;
        queue<int> Q;
        int idx = 0;
        while( idx < n ){
            queue<int> Qtmp;
            while( !Q.empty() ){
                auto start = Q.front();
                Q.pop();
                
                if( start - 1 >= 0 && s[start-1] == s[idx] ){
                    Qtmp.push(start-1);
                    count++;
                }
                
                if( start+1 == idx && s[start] == s[idx] ){
                    Qtmp.push(start);
                    count++;
                }
            }
            Qtmp.push(idx);
            count++;
            swap( Q, Qtmp );
            idx++;
        }
        
        
        return count;
    }
};
