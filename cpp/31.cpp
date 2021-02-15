/*
31. Next Permutation
*/

// iterative
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            if( nums[i] < nums[i+1] ){
                reverse(nums.begin()+i+1, nums.end());
                for(int j = i+1; j < nums.size(); j++){
                    if( nums[i] < nums[j] ){
                        swap( nums[i], nums[j] );
                        return;
                    }
                }
            }
        }
        
        reverse( nums.begin(), nums.end() );
    }
};


// recurssive v1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if( !helper(nums, 0) )
            reverse(nums.begin(), nums.end());
    }
    
    bool helper(vector<int>& nums, int idx){
        if( idx == nums.size()-1 )
            return false;
        
        if( helper(nums, idx+1) )
            return true;
        
        // [idx+1, end) is sorted in decsending order
        
        // [idx, end) is sorted in decsending order
        if( nums[idx] >= nums[idx+1] )
            return false;
        
        reverse(nums.begin()+idx+1, nums.end());
        for(int i = idx+1; i < nums.size(); i++){
            if( nums[idx] < nums[i] ){
                swap(nums[idx], nums[i]);
                break;
            }
        }
        
        return true;
    }
};

// recurssive v2

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if( !helper(nums, 0) )
            reverse(nums.begin(), nums.end());
    }
    
    bool helper(vector<int>& nums, int idx){
        if( idx == nums.size()-1 )
            return false;
        
        if( helper(nums, idx+1) )
            return true;
        
        // [idx+1, end) is sorted in decsending order
        
        // [idx, end) is sorted in decsending order
        if( nums[idx] >= nums[idx+1] )
            return false;
        
        reverse(nums.begin()+idx+1, nums.end());
        auto it = upper_bound( nums.begin()+idx+1, nums.end(), nums[idx] );
        iter_swap( nums.begin()+idx, it );
        
        return true;
    }
};


// old version
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        if( A.size() == 1 ) return;
        if( !next( A, 0 ) ) reverse(A.begin(), A.end());
    }
    
    bool next(vector<int>& A, int idx){
        if( idx + 2 == A.size() ){
            if( A[idx+1] > A[idx] ){
                swap( A[idx+1], A[idx] );
                return true;
            }
            return false;
        }
        
        if( next( A, idx+1 ) ) return true;
        
        int l = idx+1, r = A.size()-1;
        int jdx = -1, val = 1<<29;
        while( l <= r ){
            int m = (l + r) / 2;
            if( A[m] <= A[idx] ){
                r = m -1;
            }
            else{
                if( A[m] < val || (A[m] == val && m > jdx) ){
                    val = A[m];
                    jdx = m;
                }
                l = m + 1;
            }
        }
        
        if( jdx == -1 ) return false;
        
        swap( A[idx], A[jdx] );
        reverse(A.begin()+idx+1, A.end());
        return true;
    }
};
