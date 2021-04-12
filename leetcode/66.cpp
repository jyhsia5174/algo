/*
66. Plus One
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remain = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            remain += digits[i];
            digits[i] = remain % 10;
            remain /= 10;
            
            if( remain == 0 )
                break;
        }
        
        if( remain != 0 )
            digits.insert( digits.begin(), remain);
        
        return digits;
    }
};
