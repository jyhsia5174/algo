class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        vector<vector<int>> res;
        if(A.size() < 3)
            return res;
            
        sort(A.begin(), A.end());
        int j, k;
        for(int i = 0; i < A.size() - 2;){
            j = i+1;
            k = A.size() - 1;
            
            while( j < k ){
                if(A[j] + A[k] < -A[i]){
                    j++;
                }
                else if(A[j] + A[k] > -A[i]){
                    k--;
                }
                else{
                    res.push_back({A[i], A[j], A[k]});
                    while(j < k && A[j] == A[++j]){};
                    while(j < k && A[k] == A[--k]){};
                }
            }
            
            while( i < A.size() - 1 && A[i] == A[++i]){};
        }
        
        return res;
    }
};
