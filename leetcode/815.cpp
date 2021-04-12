// 815. Bus Routes
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> bus_list;
        
        const int bus_sz = routes.size();
        if( S == T ) return 0;
        if( bus_sz == 0 ) return -1;
        
        for(int i = 0; i < bus_sz; i++){
            for(auto &station: routes[i])
                bus_list[station].insert(i);
        }
        
        vector<bool> bus_visited(bus_sz, false), station_visited(1000000, false);
        int D = 0;
        queue<int> Q;
        Q.push(S);
        while( !Q.empty() ){
            queue<int> Qtmp;
            D++;
            while( !Q.empty() ){
                int station = Q.front();
                Q.pop();
                for(auto &bus: bus_list[station]){
                    if( !bus_visited[bus] ){
                        bus_visited[bus] = true;
                        for(auto &next_station: routes[bus]){
                            if( !station_visited[next_station] ){
                                station_visited[next_station] = true;
                                if( next_station == T ) return D;
                                Qtmp.push(next_station);
                            }
                        }
                    }
                }
            }
            swap( Q, Qtmp );
        }
        
        return -1;
    }
};
