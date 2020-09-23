// 1060. Missing Element in Sorted Array
class Solution {
public:
    int missingElement(vector<int>& A, int k) {
        int count = 0, base = A[0];
        for(int i = 0; i < A.size()-1; i++){
            if( count + A[i+1]-A[i]-1 >= k )
                break;
            count += A[i+1]-A[i]-1;
            base = A[i+1];
        }
        
        if( count < k )
            return base + (k-count);
        return base;
    }
};
