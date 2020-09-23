class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> Lsum;
        
        int sum = 0;
        for(int i = 0; i < L; i++)
            sum += A[i];
        Lsum.push_back(sum);
        for(int i = L; i < A.size(); i++){
            sum += -A[i-L] + A[i];
            Lsum.push_back(sum);
        }
        
        btree.resize(Lsum.size() * 4 + Lsum.size(), 0);
        init_btree(Lsum, 0, 0, Lsum.size());
        
        int result = -1;
        sum = 0;
        for(int i = 0; i < M; i++)
            sum += A[i];
        
        result = sum + get_max(M, Lsum.size(), 0, Lsum.size(), 0);
        
        int ll = 0, lr, rl, rr = Lsum.size();
        for(int i = M; i < A.size(); i++){
            // update sum
            sum += -A[i-M] + A[i];
            
            // left max
            lr = i - M + 1;
            if( lr - ll >= L)
                result = max(result, sum + get_max(ll, lr - L + 1, 0, Lsum.size(), 0));
            
            // right max
            rl = i + 1;
            if( A.size() - rl >= L)
                result = max(result, sum + get_max(rl, rr, 0, Lsum.size(), 0));
        }
        
        return result;
    }
    
private:
    vector<int> btree;
    
    void Tprint(){
        int level = 1;
        for(int i = 0; i < btree.size(); i++){
            if( i == level ){
                level = i * 2 + 1;
                cout << endl;
            }
            
            if(i % 2 == 1)
                cout << btree[i] << " ";
            else
                cout << btree[i] << "\t";
        }
        cout << endl;
    }
    
    void init_btree(vector<int>& arr, int idx, int l, int r){
        if(l+1 == r){
            btree[idx] = arr[l];
            return;
        }
        
        // init btree
        int l_idx = idx * 2 + 1, r_idx = idx * 2 + 2;
        int m = (l+r)/2;
        
        // update left
        init_btree(arr, l_idx, l, m);
        // update right
        init_btree(arr, r_idx, m, r);
        
        // update self
        btree[idx] = max(btree[l_idx], btree[r_idx]);
    }
    
    int get_max(int l, int r, int ll, int rr, int idx){
        // return best result
        if( l == ll && r == rr){
            return btree[idx];
        }
        
        int mm = (ll + rr) / 2;
        int l_idx = idx * 2 + 1, r_idx = idx * 2 + 2;
        
        if( l >= mm ){
            return get_max(l, r, mm, rr, r_idx);
        }
        else if( r <= mm ){
            return get_max(l, r, ll, mm, l_idx);
        }
        else{
            return max(get_max(l, mm, ll, mm, l_idx), get_max(mm, r, mm, rr, r_idx));
        }
    }
};
