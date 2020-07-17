// 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if( intervals.size() == 0 ) return ans;
        
        vector<pair<int, int>> A;
        for(auto &V: intervals)
            A.push_back( {V[0], V[1]} );
        sort(A.begin(), A.end());
        
        int l = A[0].first, r = A[0].second;
        for(int i = 1; i < A.size(); i++){
            if( A[i].first <= r ){
                r = max( r, A[i].second );
            }
            else{
                ans.push_back( {l, r} );
                l = A[i].first;
                r = A[i].second;
            }
        }
        ans.push_back( {l, r} );
        return ans;
    }
};
