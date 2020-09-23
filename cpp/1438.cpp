class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = 1;
        if( nums.size() == 1)
            return maxLen;
        
        int l_idx = 0;
        record[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            minval = get_min();
            maxval = get_max();
            assert( maxval >= minval );
            while(!is_valid(minval, maxval, nums[i], limit)){
                pop_record(nums[l_idx]);
                l_idx += 1;
                if(record.size() == 0)
                    break;
                minval = get_min();
                maxval = get_max();
            }
            insert_record(nums[i]);
            maxLen = max( maxLen, i - l_idx + 1);
        }
        
        return maxLen;
    }
private:
    map<int, int> record;
    int minval, maxval;
    
    void pop_record(int val){
        record[val] -= 1;
        if(record[val] == 0)
            record.erase(val);
    }
    
    void insert_record(int val){
        if(record.find(val) != record.end())
            record[val] += 1;
        else
            record[val] = 1;
    }
    
    int get_min(){
        return record.begin()->first;
    }
    
    int get_max(){
        return record.rbegin()->first;
    }
    
    bool is_valid(int min, int max, int target, int limit){
        if( target >= min && target <= max )
            return true;
        
        int abs_diff;
        if( target < min )
            abs_diff = max - target;
        else
            abs_diff = target - min;
        
        if( abs_diff > limit )
            return false;
        return true;
    }
};
