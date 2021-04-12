/*
857. Minimum Cost to Hire K Workers
Runtime: 40 ms, faster than 91.22% of C++ online submissions for Minimum Cost to Hire K Workers.
Memory Usage: 21.6 MB, less than 81.95% of C++ online submissions for Minimum Cost to Hire K Workers.
*/

typedef pair<int, double> PID;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
        int n = Q.size();
        
        vector<double> cp(n, 0);
        for(int i = 0; i < n; i++){
            cp[i] = W[i] / (double) Q[i];
        }
        
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        sort( idx.begin(), idx.end(), [&](const int &l, const int &r){
            return cp[l] < cp[r];
        } );
        
        auto cmp = [](const PID &l, const PID &r){
            return l.first < r.first;
        };
        
        priority_queue<PID, vector<PID>, decltype(cmp) > que1(cmp);
        double res = 1e20;
        double q_sum = 0;
        for(int i = 0; i < n; i++){
            int ii = idx[i];
            
            // add to Candidates
            q_sum += Q[ii];
            que1.push( {Q[ii], cp[ii]} );
            
            // pop large quality worker
            while( que1.size() > K ){
                q_sum -= que1.top().first;
                que1.pop();
            }
            
            // update 
            if( que1.size() == K ){
                //cout << q_sum << endl;
                res = min( res, q_sum * cp[ii] );
            }
        }
        
        return res;
    }
};
