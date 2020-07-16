// 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& A1, int m, vector<int>& A2, int n) {
        int i1 = 0, i2 = 0;
        vector<int> ans;
        ans.resize(m+n);
        while( i1 < m || i2 < n ){
            if( i1 < m && i2 < n ){
                if( A1[i1] <= A2[i2] ){
                    ans[i1+i2] = A1[i1];
                    i1++;
                }
                else{
                    ans[i1+i2] = A2[i2];
                    i2++;
                }
            }
            else if( i1 < m ){
                ans[i1+i2] = A1[i1];
                i1++;
            }
            else{
                ans[i1+i2] = A2[i2];
                i2++;
            }
        }
            
        for(int i = 0; i < ans.size(); i++)
            A1[i] = ans[i];
    }
};
