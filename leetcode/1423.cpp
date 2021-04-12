// 1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        vector<int> s, e;
        int N = A.size();
        
        s.resize(N+1,0);
        e.resize(N+1,0);
        for(int i = 0; i < A.size(); i++){
            s[i+1] += s[i] + A[i];
            e[i+1] += e[i] + A[N-1-i];
        }
        
        if( N <= k ) return s[N];
        
        int max_score = 0;
        for(int i = 0; i <= k; i++)
            max_score = max( max_score, s[i] + e[k-i] );
        
        return max_score;
    }
};
