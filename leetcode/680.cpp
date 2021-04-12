// 680. Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.size()-1, 0);
    }
    
    bool valid(string &s, int l, int r, int depth){
        if( depth == 2 ) return false;
        
        while( l < r ){
            if( s[l] == s[r] ){
                l++;
                r--;
            }
            else{
                if( valid(s, l+1, r, depth+1) || valid(s, l, r-1, depth+1) )
                    return true;
                return false;
            }
        }
        
        return true;
    }
};
