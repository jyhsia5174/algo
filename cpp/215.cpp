// 215. Kth Largest Element in an Array
class myQ{
public:
    myQ(){
        n = 0;
        A.resize(1, INT_MIN);
    }
    
    int size(){return n;}
    
    void push(int v){
        while( A.size() <= 2*(n+1) ){
            A.resize(A.size()*2, INT_MIN);
        }
        
        n++;
        A[n] = v;
        int idx = n;
        while( idx/2 > 0 ){
            if( A[idx] > A[idx/2] )
                swap( A[idx], A[idx/2] );
            idx /= 2;
        }
    }
    
    void pop(){
        A[1] = A[n];
        A[n] = INT_MIN;
        n--;
        int i = 1;
        while( i < (n+1) ){
            int l = i*2, r = i*2+1;
            if( A[i] >= max( A[l], A[r] ) )
                break;
            
            if(A[l] >= A[r]){
                swap(A[i], A[l]);
                i = l;
            }
            else{
                swap(A[i], A[r]);
                i = r;
            }
        }
    }
    
    int top(){
        return A[1];
    }
    
private:
    int n;
    vector<int> A;
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        myQ Q;
        
        for(int i = 0; i < nums.size(); i++){
            Q.push( -nums[i] );
            if( Q.size() > k )
                Q.pop();
        }
        
        return -Q.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        return solve(A, 0, A.size(), k);
    }
    
    int solve(vector<int> &A, int l, int r, int k){
        int pivot = (rand() % (r-l)) + l;
        
        int m = partition(A, l, r, pivot);
        cout << l << " " << r << " " << pivot << " " << m << endl;
        // (m - l) >= 1;
        
        if( m - l == k ){
            int ans = 1<<30;
            for(int i = l; i < m; i++)
                ans = min(ans, A[i]);
            return ans;
        }
        else if( (m - l) > k ){
            return solve(A, l+1, m, k);
        }
        else{
            return solve(A, m, r, k - (m - l));
        }
    }
    
    int partition(vector<int> &A, int l, int r, int pivot){
        swap(A[l], A[pivot]);
        // split l+1, r;
        int ii = l+1;
        for(int i = l+1; i < r; i++){
            if( A[i] >= A[l] ){
                swap(A[ii], A[i]);
                ii++;
            }
        }
        return ii;
    }
};
