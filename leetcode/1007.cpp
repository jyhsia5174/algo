class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        n = A.size();
        
        for(int i = 1; i <= 6; i++){
            cnt[i] = 0;
            top[i] = 0;
            bot[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            top[A[i]]++;
            bot[B[i]]++;
            if( A[i] == B[i] ){
                cnt[A[i]] ++;
            }
            else{
                cnt[A[i]] ++;
                cnt[B[i]] ++;
            }
        }
        
        vector<int> candidates;
        for(int i = 1; i <=6; i++)
            if( cnt[i] == n )
                candidates.push_back(i);
        
        if( candidates.empty() )
            return -1;
        
        int res = INT_MAX;
        for(auto x: candidates)
            res = min<int>( res, min<int>( n - top[x], n - bot[x] ) );
        
        return res;
    }
    
private:
    int n;
    int cnt[7];
    int top[7];
    int bot[7];
};
