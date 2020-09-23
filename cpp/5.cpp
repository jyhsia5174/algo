// 5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        
        string res;
        for(int i = 1; i < s.size(); i++){
            string tmp = check(i-1, s);
            if( res.size() < tmp.size() ) res = tmp;
            if(s[i-1] == s[i]){
                tmp = check_two(i-1, i, s);
                if( res.size() < tmp.size() ) res = tmp;
            }
        }
        
        string tmp = check(s.size()-1, s);
        if( res.size() < tmp.size() ) res = tmp;
        
        return res;
    }
    
    string check(int mid, string &s){
        string ss_back, ss_front;
        for(int i = 1; (mid+i < s.size()) && (mid-i >= 0); i++){
            if( s[mid+i] == s[mid-i] ){
                ss_back += s[mid+i];
                ss_front.insert(0, s, mid+i, 1);
            }
            else
                break;
        }
        
        return ss_front + s[mid] + ss_back;
    }
    
    string check_two(int l, int r, string &s){
        string ss_back, ss_front;
        for(int i = 1; (l-i >= 0) && (r+i < s.size()) ;i++ ){
            if( s[l-i] == s[r+i] ){
                ss_front.insert(0, s, l-i, 1);
                ss_back += s[r+i];
            }
            else
                break;
        }
        
        return ss_front + s[l] + s[r] + ss_back;
    }
};
