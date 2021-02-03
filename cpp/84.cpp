/*
84. Largest Rectangle in Histogram
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        return helper(H, 0, H.size());
    }
    
    // [l, r)
    int helper(vector<int>& H, int l, int r){
        if( l + 1 >= r )
            return H[l] * (r - l);
        
        int m = (l + r) / 2;
        
        int left = m, right = m+1;
        int currH = H[m];
        int maxR = 0;
        while( left >= l || right <= r ){
            if( currH == 0 )
                break;
            maxR = max( maxR, currH * (right - left) );
            if( left > l && right < r ){
                if( H[right] >= H[left-1] ){
                    currH = min( H[right], currH );
                    right++;
                }
                else{
                    left--;
                    currH = min( H[left], currH );
                }
            }
            else if( left > l ){
                left--;
                currH = min( H[left], currH );
            }
            else if( right < r ){
                currH = min( H[right], currH );
                right++;
            }
            else{
                break;
            }
        }
        
        maxR = max( maxR, helper( H, l, m) );
        maxR = max( maxR, helper( H, m, r) );
        
        return maxR;
    }
};
