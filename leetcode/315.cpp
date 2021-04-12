// 2 25m
class Solution {
public:
    vector<int> tree;
    
    void add(int x){
        while(x < tree.size()){
            tree[x]++;
            x += (x & -x);
        }
    }
    
    int get(int x){
        int res = 0;
        while(x > 0){
            res += tree[x];
            x -= (x & -x);
        }
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n+1, 0);
        
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int l, int r){
            return nums[l] < nums[r];
        });
        
        vector<int> cnt(n, 0);
        for(int i = 0; i < n;){
            int j = i+1;
            while(j < n && nums[I[i]] == nums[I[j]]) // bug1: j < n should be added
                j++;
            
            for(int k = i; k < j; k++)
                cnt[I[k]] = get(n) - get(I[k]+1);
            
            for(int k = i; k < j; k++)
                add(I[k]+1);
            i = j;
        }
        
        return cnt;
    }
};
