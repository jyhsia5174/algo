/*
344. Reverse String
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(0, s.size()-1, s);
    }
    
    void helper(int head, int tail, vector<char> &s){
        if( head >= tail )
            return;
        swap(s[head], s[tail]);
        helper( head+1, tail-1, s );
    }
};
