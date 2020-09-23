// 986. Interval List Intersections
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int idx1 = 0, idx2 = 0;
        
        vector<vector<int>> ans;
        while( idx1 < A.size() && idx2 < B.size() ){
            // move idx2
            int idx_tmp = -1;
            while( idx2 < B.size() && B[idx2][0] <= A[idx1][1] ){
                if( B[idx2][1] > A[idx1][1] && idx_tmp == -1) idx_tmp = idx2;
                vector<int> v = overlap( A[idx1], B[idx2] );
                if( !v.empty() ) ans.push_back(v); 
                idx2++;
            }
            if( idx_tmp != -1) idx2 = idx_tmp;
            
            idx1++;
        }
        
        return ans;
    }
    
    vector<int> overlap( vector<int> &l, vector<int> &r){
        vector<int> ans;
        if( l[0] > r[1] || l[1] < r[0] ) return ans;
        ans.push_back( max(l[0], r[0]) );
        ans.push_back( min(l[1], r[1]) );
        return ans;
    }
};
