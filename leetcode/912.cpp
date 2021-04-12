class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mySort(0, nums.size(), nums);
        return nums;
    }
    
    
    void mySort(int st, int ed, vector<int> &nums){
        if(st >= ed)
            return;
        
        swap(nums[st], nums[st+(rand() % (ed-st))] );
        
        int j = st+1;
        for(int i = j; i < ed; i++){
            if(nums[i] < nums[st]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        swap(nums[st], nums[j-1]);
        
        mySort(st, j-1, nums);
        mySort(j, ed, nums);
    }
    
};
