// 689. Maximum Sum of 3 Non-Overlapping Subarrays
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& A, int k) {
        if( A.size() < 3 ) return vector<int>();
        
        vector<int> ksum;
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += A[i];
        ksum.push_back(sum);
        for(int i = k; i < A.size(); i++){
            sum -= A[i - k];
            sum += A[i];
            ksum.push_back(sum);
        }
        
        stack<pair<int, int>> l_max, r_max;
        
        for(int i = ksum.size() - 1; i >= 2*k; i--){
            if( r_max.empty() ) r_max.push( {ksum[i], i} );
            else{
                if( ksum[i] >= r_max.top().first )
                    r_max.push( {ksum[i], i} );
                else
                    r_max.push( r_max.top() );
            }
        }
        l_max.push( {ksum[0], 0} );
        
        int max_sum = -1;
        vector<int> ans;
        for(int j = k; j + k < ksum.size(); j++){
            cout << j << endl;
            assert( (!l_max.empty()) && (!r_max.empty()) );
            auto &r_pp = r_max.top();
            auto &l_pp = l_max.top();
            if( ksum[j] + r_pp.first + l_pp.first > max_sum ){
                max_sum = ksum[j] + r_pp.first + l_pp.first;
                vector<int> tmp {l_pp.second, j, r_pp.second};
                swap( ans, tmp );
            }
            
            if( ksum[j-k+1] > l_pp.first )
                l_max.push( {ksum[j-k+1], j-k+1} );
            else
                l_max.push( {l_pp.first, l_pp.second} );
            r_max.pop();
        }
        cout << max_sum << endl;
        return ans;
    }
};
