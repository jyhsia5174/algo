//  Count of Smaller Numbers After Self
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexs, counts;
        indexs.resize(n, 0);
        counts.resize(n, 0);
        iota(indexs.begin(), indexs.end(), 0);
        
        solve( nums, indexs, 0, n, counts);
        
        return counts;
    }
    
    void solve(vector<int>& nums, vector<int>& indexs, int l, int r, vector<int>& counts ){
        if( r - l <= 1 )
            return;
        
        int m = (l + r) / 2;
        solve(nums, indexs, l, m, counts);
        solve(nums, indexs, m, r, counts);
        
        int i = l, j = m;
        int r_count = 0;
        
        vector<int> tmp;
        tmp.resize(r - l, 0);
        int tmp_idx = 0;
        while( i < m || j < r ){
            if( i >= m ){
                tmp[tmp_idx] = indexs[j];
                j++;
                r_count++;
            }
            else if( j >= r ){
                tmp[tmp_idx] = indexs[i];
                counts[indexs[i]] += r_count;
                i++;
            }
            else{
                if( nums[indexs[i]] > nums[indexs[j]] ){
                    tmp[tmp_idx] = indexs[j];
                    j++;
                    r_count++;
                }
                else{
                    tmp[tmp_idx] = indexs[i];
                    counts[indexs[i]] += r_count;
                    i++;
                }
            }
            tmp_idx++;
        }
        
        for(int k = 0; k < r - l; k++)
            indexs[l+k] = tmp[k];
        
    }
};
