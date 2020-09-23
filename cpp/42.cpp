// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& H) {
        int ans = 0;
        stack<pair<int, int>> S;
        for(int i = 0; i < H.size(); i++){
            if( S.empty() ){
                S.push( {i, H[i]} );
                continue;
            }
            
            int sum = 0;
            int pos, h;
            while( !S.empty() && S.top().second < H[i] ){
                pos = S.top().first;
                h = S.top().second;
                S.pop();
                if( !S.empty() ){
                    sum += h * (pos - S.top().first);
                }
            }
            
            if( S.empty() ){
                ans += (i - pos - 1) * h;
            }
            else{
                ans += (i - S.top().first - 1) * H[i];
            }
            ans -= sum;
            
            S.push( {i, H[i]} );
        }
        
        return ans;
    }
};
