class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            int v = target - nums[i];
            
            if( m.find(v) != m.end() ){
                return {m[v], i};
            }
            
            m[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};


// Old version

#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> my_hash;
        vector<int> res;
        for(int i=0; i < nums.size(); i++){
            int supplement = target - nums[i];
            if(my_hash.find(supplement) != my_hash.end()){
                unordered_map<int, int>::const_iterator got = my_hash.find(supplement);
                res.push_back(i);
                res.push_back(got->second);
                return res;
            }
            my_hash.emplace(nums[i], i);
        }
        return res;
    }
    
};
