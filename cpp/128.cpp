class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        all_val.insert(nums.begin(), nums.end());
        
        int res = 0;
        for(auto a: all_val){
            if( !is_checked(a) ){
                res = max<int>( res, get_size(a));
            }
        }
        
        return res;
    }
    
    int get_size(int i){
        int res = 1;
        checked_val.insert(i);
        
        if( i < INT_MAX )
            if( !is_checked(i+1) && existed(i+1) )
                res += get_size(i+1);
        if( i > INT_MIN )
            if( !is_checked(i-1) && existed(i-1) )
                res += get_size(i-1);
        
        return res;
    }
    
private:
    bool is_checked(int a){ return (checked_val.find(a) != checked_val.end());}
    bool existed(int a){ return (all_val.find(a) != all_val.end());}
    unordered_set<int> checked_val;
    unordered_set<int> all_val;
};
