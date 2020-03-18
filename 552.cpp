class Solution {
public:
    
    typedef long long int lli;
    
    int checkRecord(int n) {
        
        const lli m = 1000000007;
        if( n == 0 ) return 0;
        
        lli a[7], b[7];
        for(int i = 0; i < 7; i++)
            a[i] = 0;
        a[0] = 1;
        a[4] = 1;
        a[5] = 1;
        
        for(int i = 1; i < n; i++){
            b[0] = a[4] + a[5] + a[6];
            b[1] = a[0] + a[1] + a[2] + a[3];
            b[2] = a[0] + a[1];
            b[3] = a[2];
            b[4] = a[4] + a[5] + a[6];
            b[5] = a[4];
            b[6] = a[5];
            
            for(int j = 0; j < 7; j++){
                a[j] = b[j] % m;
            }
        }
        
        int res = 0;
        for(int j = 0; j < 7; j++)
            res = (res + a[j]) % m;
        
        return res;
    }
};
