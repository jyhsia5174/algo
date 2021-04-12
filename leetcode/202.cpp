class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        int res = false;
        while(cnt <= 162){
            if( n == 1 ){
                res = true;
                break;
            }
            n = happy(n);
            
            if( n <= 162 )
                cnt ++;
        }
        
        return res;
    }
    
    int happy(int n){
        int res = 0;
        while(n > 0){
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
};
