#include <limits.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        
        int min_len = INT_MAX;
        for(auto str: strs)
            min_len = min<unsigned int>( str.size(), min_len);
        
        if( min_len == 0 || strs.size() == 0)
            return s;
        
        int i = 0;
        bool is_valid;
        char c = strs[0][i];
        while( i < min_len ){
            is_valid = true;
            for(auto str: strs){
                if( c != str[i] ){
                    is_valid = false;
                    break;
                }
            }
            
            if( is_valid )
                s += c;
            else
                break;
            
            i++;
            c = strs[0][i];
        }
        
        return s;
    }
};
