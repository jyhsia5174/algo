// 1376. Time Needed to Inform All Employees
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& M, vector<int>& T) {
        unordered_map<int, vector<int>> S;
        for(int i = 0; i < M.size(); i++)
            if( M[i] >= 0 )
                S[M[i]].push_back(i);
            
        
        int max_T = 0;
        queue<pair<int, int>> Q;
        Q.push({headID, 0});
        while(!Q.empty()){
            queue<pair<int, int>> Q_tmp;
            while(!Q.empty()){
                auto pp = Q.front();
                Q.pop();
                int id = pp.first;
                int t = pp.second;
                int t_next = t + T[id];
                if( S.count(id) == 0 ) continue;
                max_T = max(max_T, t_next);
                for(auto sub_id: S[id])
                    Q_tmp.push( {sub_id, t_next} );
            }
            swap( Q, Q_tmp);
        }
        
        return max_T;
    }
};
