class Solution {
public:
    
    vector<int> A; // A[i] = a0 + ... + ai ,  A[j] - A[i] = aj + ... + a(i+1) given j > i;
    
    int maximizeSweetness(vector<int>& S, int K) {
        int N = S.size();
        A.resize( N, 0);
        A[0] = S[0];
        for(int i = 1; i < A.size(); i++)
            A[i] = A[i-1] + S[i];
        
        for(int i = 0; i < A.size(); i++)
            cout << A[i] << " " ;
        cout << endl;
        
        int s = 0, e = A[N-1] / (double) (K+1) + 1;
        while( e - s > 1 ){
            int m = (s + e) / 2;
            cout << s << setw(10) << e << endl;
            if( valid(m, K) )
                s = m;
            else
                e = m;
        }
        
        return s;
    }
    
    bool valid( int m, int K ){
        auto it = A.begin();
        int count = 0;
        int cur_sum = 0;
        
        while( count < K + 1 ){
            it = lower_bound( it, A.end(), cur_sum + m );
            if( it == A.end() )
                return false;
            count++;
            cur_sum = (*it);
        }
        
        return true;
    }
};
