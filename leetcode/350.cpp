/*
350. Intersection of Two Arrays II
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > nums1.size() )
            swap(nums1, nums2);
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        nums1.erase(set_intersection(begin(nums1), end(nums1),
        begin(nums2), end(nums2), begin(nums1)), end(nums1));
        return nums1;
    }
    
};
