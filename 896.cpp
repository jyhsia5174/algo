// 896. Monotonic Array
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int type = 0;
        
        for(int i = 1; i < A.size(); i++){
            int diff = A[i] - A[i-1];
            if( diff == 0 ){
                continue;
            }
            else if( diff > 0 ){
                if( type == -1 ) return false;
                type = 1;
            }
            else{
                if( type == 1 ) return false;
                type = -1;
            }
        }
            
        return true;
    }
};
