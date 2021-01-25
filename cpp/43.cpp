/*
43. Multiply Strings
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Multiply Strings.
Memory Usage: 6.5 MB, less than 95.48% of C++ online submissions for Multiply Strings.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res(n1 + n2, '0');
        
        
        // n1+n2+1 == 0 
        for( int i = n1-1; i >= 0; i-- ){
            int carry = 0;
            for(int j = n2-1; j >= 0; j-- ){
                int k = i+j+1;
                int tmp = (num1[i] - '0') * (num2[j] - '0') + (res[k] - '0') + carry;
                res[k] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            res[i] += carry;
        }
        
        size_t pos = res.find_first_not_of('0');
        if( pos != string::npos )
            return res.substr( pos, res.size() - pos );
        
        return "0";
    }
};
