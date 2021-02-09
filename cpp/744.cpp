/*
744. Find Smallest Letter Greater Than Target
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        while( lo+1 < hi ){
            int mid = lo + (hi - lo) / 2;
            if( letters[mid] == target )
                lo = mid;
            else if( letters[mid] < target )
                lo = mid;
            else
                hi = mid;
        }
        
        // lo + 1 == hi
        if( letters[lo] > target )
            return letters[lo];
        if( letters[hi] > target )
            return letters[hi];
        return letters[0];
    }
};
