// 528. Random Pick with Weight
class Solution {
public:
    Solution(vector<int>& w) {
        sum.resize(w.size()+1, 0);
        for(int i = 0; i < w.size(); i++)
            sum[i+1] = sum[i] + w[i];
    }
    
    int pickIndex() {
        int val = rand() % sum[sum.size()-1];
        
        int l = 0, r = sum.size();
        int ans_val = (1<<30);
        int ans_idx = -1;
        while( l <= r ){
            int m = (l + r) / 2;
            if( sum[m] > val ){
                if( ans_val > sum[m] ){
                    ans_val = sum[m];
                    ans_idx = m;
                }
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        
        return ans_idx-1;
    }
private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
