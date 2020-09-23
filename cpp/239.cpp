// 239. Sliding Window Maximum
class Solution {
public:
    void clean(deque<int> &Q, int idx, vector<int>& nums, int k){
        while( (!Q.empty()) && Q.front() <= idx-k )
            Q.pop_front();
        
        while( (!Q.empty()) && nums[Q.back()] < nums[idx] )
            Q.pop_back();
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result( nums.size()-(k-1) );
        
        deque<int> Q;
        for(int i = 0; i < k-1; i++){
            clean( Q, i, nums, k);
            Q.push_back( i );
        }
        
        for(int i = 0; i < result.size(); i++){
            clean(Q, i+(k-1), nums, k);
            Q.push_back(i+(k-1));
            result[i] = nums[Q.front()];
        }
        
        return result;
    }
};
