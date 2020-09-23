class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        E.resize(N);
        for(int i = 0; i < times.size(); i++){
            int st = times[i][0] - 1;
            int to = times[i][1] - 1;
            int cost = times[i][2];
            
            E[st].push_back( {to, cost} );
        }
        
        T.resize(N);
        for(int i = 0; i < N; i++)
            T[i] = INF;
        
        queue<int> Q;
        Q.push(K-1);
        T[K-1] = 0;
        while(!Q.empty()){
            int a = Q.front();
            Q.pop();
            
            for(int i = 0; i < E[a].size(); i++){
                int to = E[a][i].first;
                int cost = E[a][i].second;
                
                if( T[a] + cost < T[to] ){
                    T[to] = T[a] + cost;
                    Q.push(to);
                }
            }
        }
        
        int result = 0;
        for(int i = 0; i < N; i++)
            result = max(result, T[i]);
        
        if(result == INF)
            return -1;
        return result;
    }
private:
    vector<vector<pair<int, int>>> E;
    vector<int> T;
    const int INF = 1 << 30;
};
