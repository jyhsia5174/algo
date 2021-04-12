// 210. Course Schedule II
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
        vector<vector<int>> E(N);
        vector<int> count(N, 0);
        
        for(auto &v: P){
            E[v[1]].push_back(v[0]);
            count[v[0]]++;
        }
        
        vector<int> res;
        vector<int> count2(N, 0);
        queue<int> Q;
        for(int i = 0; i < N; i++)
            if( count[i] == 0 )
                Q.push(i);
        
        while(!Q.empty()){
            queue<int> Qtmp;
            while(!Q.empty()){
                int cur_n = Q.front();
                res.push_back(cur_n);
                Q.pop();
                
                for(auto &next_n: E[cur_n]){
                    count2[next_n]++;
                    if( count2[next_n] == count[next_n] )
                        Qtmp.push(next_n);
                }
            }
            swap(Q, Qtmp);
        }
        
        if( res.size() == N)
            return res;
        return vector<int> ();
    }
};
