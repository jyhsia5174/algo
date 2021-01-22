/*
56. Merge Intervals
Runtime: 12 ms, faster than 99.83% of C++ online submissions for Merge Intervals.
Memory Usage: 14.2 MB, less than 97.05% of C++ online submissions for Merge Intervals.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        sort( I.begin(), I.end(), [](const vector<int> &l, const vector<int> &r){
            return l[0] < r[0];
        } );
        
        vector<vector<int>> res;
        if( I.size() == 0 )
            return res;
        int l = I[0][0], r = I[0][1];
        for(int i = 1; i < I.size(); i++){
            vector<int> &v = I[i];
            if( v[0] > r ){
                res.push_back( {l, r} );
                l = v[0];
                r = v[1];
            }
            else{
                r = max( r, v[1] );
            }
        }
        res.push_back( {l, r} );
        
        return res;
    }
};

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
