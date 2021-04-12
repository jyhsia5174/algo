// 825. Friends Of Appropriate Ages
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        
        int ans = 0;
        for(int i = 0; i < ages.size(); i++)
            ans += request(i, ages);
        
        return ans;
    }
    
    int request(int i, vector<int> &A){
        if( A[i] <= 14 ) return 0;
        
        int min_v = 0.5 * A[i] + 7 + 1;
        int max_v = A[i];
        
        auto lit = lower_bound(A.begin(), A.end(), min_v);
        auto rit = upper_bound(A.begin(), A.end(), max_v);
        
        return (rit - lit) - 1;
    }
};
