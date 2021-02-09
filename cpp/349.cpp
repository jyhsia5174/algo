/*
349. Intersection of Two Arrays
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() < nums2.size() )
            swap(nums1, nums2);
        unordered_set<int> S1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        
        for(auto &v: nums2)
            if( S1.find(v) != S1.end() )
                res.insert(v);
        
        return vector<int>(res.begin(), res.end());
    }
};
