560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        for(int i = 1; i < A.size(); i++)
            A[i] += A[i-1];
        
        for(int i = 0; i < A.size(); i++)
            counts[A[i]] ++;
        
        int result = 0;
        if(counts.find(k) != counts.end())
            result += counts[k];
        counts[A[0]]--;
        for(int i = 0; i < A.size() - 1; i++){
            int val = k + A[i];
            
            if( counts.find(val) != counts.end() )
                result += counts[val];
            
            counts[A[i+1]]--;
        }
        
        return result;
    }
private:
    unordered_map<int, int> counts;
};
