class Solution {
public:
    int confusingNumberII(int N) {
        limit = N;
        int res = 0;
        
        for(auto a : valid_nums )
            if(a != 0)
                res += find(a);
        return res;
    }
    
    int find(int num){
        int res = 0;
        if(num > limit)
            return res;
        
        if( !is_same(num) )
            res++;
        
        for(auto a: valid_nums){
            if( num > INT_MAX / 10 )
                break;
            res += find(num*10 + a);
        }
        
        return res;
    }
        
private:
    int limit;
    vector<int> valid_nums{0, 1, 6, 8, 9};
        
    bool is_same(int N){
        int N_inv = 0;
        int N_cp = N;
        while(N > 0){
            N_inv = N_inv * 10 + flip(N % 10);
            N /= 10;
        }
        
        if( N_inv == N_cp )
            return true;
        return false;
    }
        
    int flip(int num){
        int res;
        switch(num){
            case 0: res = 0;
                    break;
            case 1: res = 1;
                    break;
            case 6: res = 9;
                    break;
            case 8: res = 8;
                    break;
            case 9: res = 6;
                    break;
            default: cerr << "wrong " << num << endl;
        }
        return res;
    }
};
