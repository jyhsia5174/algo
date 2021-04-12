/*
11. Container With Most Water
*/

// n
class Solution {
public:
    int maxArea(vector<int>& H) {
        const int n = H.size();
        if( n == 1 || n == 0 )
            return 0;
        
        int lo = 0, hi = n-1;
        int res = 0;
        while( lo < hi ){
            res = max( res, (hi - lo)*min(H[lo], H[hi]) );
            if( H[lo] <= H[hi] ){
                lo++;
            }
            else{
                hi--;
            }
        }
        
        return res;
    }
};

// n log n
class Solution {
public:
    int maxArea(vector<int>& H) {
        const int n = H.size();
        if( n == 1 || n == 0 )
            return 0;
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        
        sort(idx.begin(), idx.end(), [&](const int &l, const int &r){
            return H[l] > H[r];
        } );
        
        int front = INT_MAX;
        int tail = INT_MIN;
        int res = 0;
        for(int i = 0; i < n; i++){
            int pos = idx[i];
            int height = H[pos];
            // front
            if( front < pos )
                res = max( res, (pos - front) * height );
            
            // tail
            if( tail > pos )
                res = max( res, (tail - pos) * height );
            
            // update
            front = min(front, pos);
            tail = max(tail, pos);
        }
        
        return res;
    }
};
