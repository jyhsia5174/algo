/*
12. Integer to Roman
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

99 
1000 -> 900 -> 500 -> 400 -> 100 -> 90 -> 50 -> 40 -> 10 -> 9 -> 5 -> 
*/

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        
        for(int i = 0; i < rom.size(); i++){
            int cnt = num / val[i];
            num -= cnt * val[i];
            while( cnt > 0 ){
                res += rom[i];
                cnt--;
            }
        }
        
        return res;
    }

private:
    vector<string> rom{"M", "CM", "D", "CD", 
                       "C", "XC", "L", "XL",
                       "X", "IX", "V", "IV", 
                       "I"};
    vector<int>    val{1000, 900, 500, 400, 
                       100, 90, 50, 40, 
                       10, 9, 5, 4, 
                       1};
};
