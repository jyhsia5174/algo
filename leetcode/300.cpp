// 300. Longest Increasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        vector<int> dp;
        
        for(auto &v: nums){
            auto it = lower_bound(dp.begin(), dp.end(), v);
            if( it == dp.end() ){
                dp.push_back(v);
            }
            else{
                (*it) = v;
            }
        }
        
        return dp.size();
    }
};

/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        map<int, int> record;
        for(int i = 0; i < n; i++){
            if( record.size() == 0 ){
                record[nums[i]] = 1;
                continue;
            }
            
            auto it = record.upper_bound(nums[i]);
        
            int L;
            if( it == record.begin() )
                L = 1;
            else{
                it--;
                if( it->first < nums[i] )
                    L = it->second + 1;
                else
                    L = it->second;
            }
            record[nums[i]] = L;
                
            auto it2 = record.upper_bound(nums[i]);
            auto it3 = record.upper_bound(nums[i]);
            for(it3 = it2; it3 != record.end(); it3++)
                if( it3->second > L )
                    break;
            record.erase(it2, it3);
        }
        
        
        return record.rbegin()->second;
    }
};*/
