/*
744. Find Smallest Letter Greater Than Target
*/

// template 1
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        int loc = -1;
        while( lo <= hi ){
            int mid = lo + (hi - lo) / 2;
            if( letters[mid] == target )
                lo = mid + 1;
            else if( letters[mid] < target )
                lo = mid + 1;
            else{
                loc = mid;
                hi = mid - 1;
            }
        }
        
        if( loc != -1 )
            return letters[loc];
        // lo - 1 == hi
        return letters[0];
    }
};

// template 2

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        int loc = -1;
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;
            if( letters[mid] == target )
                lo = mid + 1;
            else if( letters[mid] < target )
                lo = mid + 1;
            else{
                loc = mid;
                hi = mid;
            }
        }
        
        // lo == hi
        if( loc != -1 )
            return letters[loc];
        return letters[0];
    }
};

// template 3
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
