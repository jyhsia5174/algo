class segT{
public:
    segT(int _n){
        n = _n;
        tree.resize(2*n, 0);
    }
    
    void insert(int idx, int val){
        idx += n;
        tree[idx] = val;
        idx /= 2;
        while( idx > 0 ){
            tree[idx] = tree[idx*2] + tree[idx*2 + 1]; 
            idx /= 2;
        }
    }
    
    int sum(int l, int r){
        l += n;
        r += n;
        
        int res = 0;
        while( l <= r ){
            if( l % 2 == 1 ){
                res += tree[l];
                l++;
            }
            
            if( r % 2 == 0 ){
                res += tree[r];
                r--;
            }
            
            l /= 2;
            r /= 2;
        }
        return res;
    }
    
private:
    vector<int> tree;
    int n;
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        segT T = segT(n);
        
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        
        sort( idx.begin(), idx.end(), [&](const int &l, const int &r){
            return nums[l] > nums[r];
        } );
        
        int res = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            long long int val = 2;
            val *= nums[idx[i]];
            while(j < n){
                if(nums[idx[j]] >  val){
                    T.insert(idx[j], 1);
                    j++;
                }
                else{
                    break;
                }
            }
            res += T.sum(0, idx[i]-1);
        }
        
        return res;
    }
};
