/*
307. Range Sum Query - Mutable
*/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize( 2*n, 0 );
        build_tree( nums );
    }
    
    void build_tree(vector<int>& nums){
        for(int i = n; i < 2*n; i++)
            tree[i] = nums[i - n];
        for(int i = n-1; i >= 1; i--)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    void update(int index, int val) {
        int pos = index + n;
        tree[pos] = val;
        
        pos /= 2;
        while( pos > 0 ){
            int left = pos*2;
            int right = pos*2 + 1;
            tree[pos] = tree[left] + tree[right];
            pos /= 2;
        }
    }
    
    int sumRange(int l, int r) {
        l += n;
        r += n;
        
        int sum = 0;
        while( l <= r ){
            if( (l % 2) == 1 ){
                sum += tree[l];
                l++;
            }
            
            if( (r % 2) == 0 ){
                sum += tree[r];
                r--;
            }
                
            
            l /= 2;
            r /= 2;
        }
        
        return sum;
    }
    
private:
    int n;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
