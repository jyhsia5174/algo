// 670. Maximum Swap
class Solution {
public:
    int maximumSwap(int num) {
        
        stack<int> max_D;
        priority_queue<int, vector<int>, greater<int>> base_sets[10];
        
        int base = 1;
        while( num >= base ){
            int d = (num / base) % 10;
            base_sets[d].push(base);
            if( !max_D.empty() ) max_D.push( max( d, max_D.top() ) );
            else max_D.push(d);
            base *= 10;
        }
        
        int ans = num;
        base /= 10;
        while( base > 0 ){
            int d = (num / base) % 10;
            if( max_D.top() > d ){
                // switch 
                int dd = max_D.top();
                int dd_base = base_sets[dd].top();
                
                ans += d * ( dd_base - base);
                ans += dd * ( base - dd_base);
                
                break;
            }
            else{
                max_D.pop();
            }
            base /= 10;
        }
        
        return ans;
    }
};
