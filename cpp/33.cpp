class Solution {
public:
    int search(vector<int>& nums, int target) {
        if( nums.size() == 0 )
            return -1;
        return find(nums, 0, nums.size(), target);
    }
    
    int find(vector<int>& nums, int begin, int end, int T){
        if(begin + 1 == end){
            if(nums[begin] == T)
                return begin;
            else
                return -1;
        }
        
        int mid = (begin + end) / 2;
        int res = -1;
        if( nums[mid] < nums[begin] && nums[mid] < nums[end-1] ){
            res = bi_search(nums, mid, end, T);
            if( res == -1 )
                res = find(nums, begin, mid, T);
        }
        else{
            res = bi_search(nums, begin, mid, T);
            if(res == -1)
                res = find(nums, mid, end, T);
        }
        
        return res;
    }
    
    int bi_search(vector<int>& nums, int begin, int end, int T){
        if(begin + 1 == end){
            if(nums[begin] == T)
                return begin;
            else
                return -1;
        }
        
        int mid = (begin + end) / 2;
        int res = -1;
        if(nums[mid] <= T)
            res = bi_search(nums, mid, end, T);
        else
            res = bi_search(nums, begin, mid, T);
        
        return res;
    }
};
