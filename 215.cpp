// 215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        return solve(A, 0, A.size(), k);
    }
    
    int solve(vector<int> &A, int l, int r, int k){
        int pivot = (rand() % (r-l)) + l;
        
        int m = partition(A, l, r, pivot);
        cout << l << " " << r << " " << pivot << " " << m << endl;
        // (m - l) >= 1;
        
        if( m - l == k ){
            int ans = 1<<30;
            for(int i = l; i < m; i++)
                ans = min(ans, A[i]);
            return ans;
        }
        else if( (m - l) > k ){
            return solve(A, l+1, m, k);
        }
        else{
            return solve(A, m, r, k - (m - l));
        }
    }
    
    int partition(vector<int> &A, int l, int r, int pivot){
        swap(A[l], A[pivot]);
        // split l+1, r;
        int ii = l+1;
        for(int i = l+1; i < r; i++){
            if( A[i] >= A[l] ){
                swap(A[ii], A[i]);
                ii++;
            }
        }
        return ii;
    }
};
