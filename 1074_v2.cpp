class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        m = A.size();
        n = A[0].size();
        
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                A[i][j] += A[i][j-1];
        
        for(int x1 = 0; x1 < n; x1++){
            for(int x2 = x1; x2 < n; x2++){
                unordered_map<int, int> counter;
                counter[0] = 1;
                int cur = 0;
                for(int k = 0; k < m ; k++){
                    cur += A[k][x2] - ( x1 > 0 ? A[k][x1-1] : 0 );
                    count += counter[cur - target];
                    counter[cur]++;
                }
                
            }
        }
        
        return count;
    }

private:
    int count = 0;
    int m, n;
};
