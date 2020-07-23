// 523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<unsigned int> sum;
        const int N = nums.size();
        if( N < 2 ) return false;
        
        sum.resize( N+1, 0 );
        
        k = abs(k);
        
        if( k == 0 ){
            int ii = 0, jj = 0;
            while( ii <= jj && jj < nums.size() ){
                if( jj - ii >= 2 ) return true;
                if( nums[jj] == 0 ) jj++;
                else ii = jj = jj+1;
            }
            if( jj - ii >= 2 ) return true;
            return false;
        }
        
        unordered_map<int, unordered_set<int>> S;
        for(int i = 0; i < nums.size(); i++){
            sum[i+1] = ( sum[i] + (unsigned int) nums[i] ) % k;
            S[sum[i+1]].insert(i+1);
        }
        
        S[sum[1]].erase( 1 );
        if( !S[0].empty() ) return true;
        for(int i = 0; i + 1 < N; i++){
            if( !S[sum[i]].empty() ) return true;
            S[sum[i+2]].erase(i+2);
        }
        
        return false;
    }
};
