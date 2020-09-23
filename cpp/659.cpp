class Solution {
public:
    bool isPossible(vector<int>& A) {
        int pre_cnt=0, cur_cnt=0;
        int cur_val;
        queue<int> myque;
        
        for(int i = 0; i < A.size();){
            //Get current A[i] counts
            cur_cnt = 1;
            cur_val = A[i];
            while( ++i < A.size() && A[i-1] == A[i] ){ cur_cnt ++; }
            
            //Check pre_cnt - cur_cnt 
            if( pre_cnt > cur_cnt ){
                while( (pre_cnt--) > cur_cnt ){
                    if( myque.front() + 2 >= cur_val) return false;
                    myque.pop();
                }
            }
            else{
                while( cur_cnt > (pre_cnt++) ){
                    myque.push(cur_val);
                }
            }
            

            while(  ( i == A.size() || cur_val + 1 != A[i] ) && cur_cnt-- ){
                if( myque.front() + 2 > cur_val ) return false;
                myque.pop();
            }
            
            pre_cnt = cur_cnt;
        }
        
        return true;
    }
};
