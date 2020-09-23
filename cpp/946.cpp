// Validate Stack Sequences
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if( pushed.size() != popped.size() )
            return false;
        if( pushed.size() == 0 )
            return true;
        
        int k = 0, kk = 0;
        stack<int> s;
        s.push(pushed[0]);
        kk ++;
        
        while(k < popped.size()){
            while( s.empty() || s.top() != popped[k] ){
                if( kk >= pushed.size() )
                    return false;
                s.push(pushed[kk]);
                kk++;
            }
            s.pop();
            k++;
        }
        
        return true;
    }
};
