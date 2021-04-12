// 871. Minimum Number of Refueling Stops
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& S) {
        
        int N = S.size();
        int cur_pos = 0;
        int cur_fuel = startFuel;
        int count = 0;
        priority_queue<int> Q;
        for(int i = 0; i < N; i++){
            if( (S[i][0] - cur_pos) <= cur_fuel ){
                cur_fuel -= S[i][0] - cur_pos;
                cur_pos = S[i][0];
                Q.push( S[i][1] );
            }
            else{
                while( cur_fuel < (S[i][0] - cur_pos) ){
                    if( Q.empty() )
                        return -1;
                    cur_fuel += Q.top();
                    count++;
                    Q.pop();
                }
                cur_fuel -= S[i][0] - cur_pos;
                cur_pos = S[i][0];
                Q.push( S[i][1] );
            }
        }
        
        while( cur_fuel < (target - cur_pos) ){
            if( Q.empty() )
                return -1;
            cur_fuel += Q.top();
            count++;
            Q.pop();
        }
        
        return count;
    }
};
