// 647. Palindromic Substrings
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
