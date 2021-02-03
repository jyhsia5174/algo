/*
307. Range Sum Query - Mutable
*/


class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n+2, 0);
        
        for(int i = 0; i < nums.size(); i++)
            inc(i, 0, nums[i]);
    }
    
    void update(int index, int val) {
        int preV = sumRange(index, index);
        inc( index, preV, val);
    }
    
    int sumRange(int left, int right) {
        return get(right) - get(left-1);
    }
    
    int get(int x){
        int res = 0;
        while( x >= 0 ){
            res += tree[x];
            x = ( x & (x+1) ) - 1;
        }
        return res;
    }
    
    
    void inc(int x, int preV, int V){
        int diff = V - preV;
        
        while( x < tree.size() ){
            tree[x] += diff;
            x = x | (x+1);
        }
    }
    
    int n;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */




// old version 
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
