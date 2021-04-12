class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        n = A.size();
        
        for( int i = 0; i < 2; i++ ){
            cnt[i][0] = 0;
            cnt[i][1] = 1;
        }
        
        int a = A[0];
        int b = B[0];
        int aa, bb;
        for(int i = 1; i < n; i++){
            if( cnt[0][0] == -1 && cnt[1][0] == -1)
                return -1;
            
            aa = A[i];
            bb = B[i];
            
            if( aa != a && bb != a )
                cnt[0][0] = -1;
            
            if( aa != b && bb != b )
                cnt[1][0] = -1;
            
            if( aa == bb )
                continue;
            
            if( cnt[0][0] != -1 ){
                if( aa == a ){
                    cnt[0][1]++;
                }
                else{
                    cnt[0][0]++;
                }
            }
            
            if( cnt[1][0] != -1 ){
                if( bb == b ){
                    cnt[1][1]++;
                }
                else{
                    cnt[1][0]++;
                }
            }
        }
        
        int res = INT_MAX;
        for( int i = 0; i < 2; i++ )
            if( cnt[i][0] != -1)
                for(int j = 0; j < 2; j++)
                    res = min<int>( res, cnt[i][j] );
                
        return res;
    }
    
private:
    int n;
    int cnt[2][2];
};
