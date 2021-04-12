// 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& P) {
        int res = 0;
        if( P.size() <= 1 ) return res;
        
        int Lmin = P[0];
        for(int i = 1; i < P.size(); i++){
            res = max( P[i] - Lmin, res );
            Lmin = min( Lmin, P[i] );
        }
        
        return res;
    }
};
