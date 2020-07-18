// 973. K Closest Points to Origin
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& P, int K) {
        priority_queue<pair<int, int>> Q;
        
        for(int i = 0; i < P.size(); i++){
            auto &p = P[i];
            int dist = p[0]*p[0] + p[1]*p[1];
            if( Q.size() < K ){
                Q.push( {dist, i} );
            }
            else{
                if( Q.top().first > dist ){
                    Q.pop();
                    Q.push( {dist, i} );
                }
            }
        }
        
        vector<vector<int>> ans;
        while( !Q.empty() ){
            ans.push_back( P[Q.top().second] );
            Q.pop();
        }
        
        return ans;
    }
};
