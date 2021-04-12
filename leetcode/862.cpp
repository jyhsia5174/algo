class Solution {
public:
    
    typedef long long int lli;
    
    int shortestSubarray(vector<int>& A, int K) {
        int L = A.size();
        lli *P = new lli[L+1];
        P[0] = 0;
        for(int i = 0; i < L; i++)
            P[i+1] = P[i] + A[i];
        
        int ans = L + 1;
        deque<int> dq;
        
        for(int y = 0; y < L+1; y++){
            while( !dq.empty() && P[y] <= P[dq.back()] )
                dq.pop_back();
            
            while( !dq.empty() && P[y] >= P[dq.front()] + K ){
                ans = min<int>( ans, y - dq.front() );
                dq.pop_front();
            }
            
            dq.push_back(y);
        }
        
        return ans < L+1 ? ans : -1;
    }
};
