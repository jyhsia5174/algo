class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        set<vector<int>> res;
        if(A.size() < 3)
            return vector<vector<int>>(res.begin(), res.end());
            
        sort(A.begin(), A.end());
        
        int j, k;
        for(int i = 0; i < A.size() - 2; i++){
            j = i+1;
            k = A.size() - 1;
            
            while( j != k ){
                while( A[j] + A[k] < -A[i] ){
                    if( j == k - 1)
                        break;
                    j++;
                }
                
                if( A[i] + A[j] + A[k] == 0 )
                    res.insert({A[i], A[j], A[k]});
                
                k--;
            }
            
            if(A[i] >= 0)
                break;
        }
        
        return vector<vector<int>>(res.begin(), res.end());
    }
};
