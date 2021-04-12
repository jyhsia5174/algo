// 125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < 10; i++)
            char_map[i+'0'] = i;
        for(int i = 0; i < 26; i++){
            char_map[i+'a'] = i+10;
            char_map[i+'A'] = i+10;
        }
        
        int ii = 0, jj = s.size()-1;
        while( ii < jj ){
            while( ii < s.size() && char_map.count(s[ii]) == 0 ) ii++;
            while( jj >= 0 && char_map.count(s[jj]) == 0 ) jj--;
            if( ii >= jj ) break;
            if( char_map[s[ii]] != char_map[s[jj]] ) return false;
            ii++;
            jj--;
        }
        
        return true;
    }
    
private:
    unordered_map<char, int> char_map;
};
