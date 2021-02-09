/*
702. Search in a Sorted Array of Unknown Size
*/
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 1;
        while( reader.get(hi) != 2147483647 )
            hi <<= 2;
        
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;
            if( reader.get(mid) == target )
                return mid;
            else if( reader.get(mid) > target )
                hi = mid;
            else
                lo = mid + 1;
        }
        
        // lo == hi
        return -1;
    }
};
