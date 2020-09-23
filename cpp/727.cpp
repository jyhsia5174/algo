class Solution {
public:
    string minWindow(string S, string T) {
        for(int i = 0; i < S.size(); i++){
            if( S[i] == T[0] )
                myque.push({i, i+1});
        }
        
        for(int i = 1; i < T.size(); i++){
            queue<pair<int, int>> que_tmp;
            while( !myque.empty() ){
                pair<int, int> substr = myque.front();
                myque.pop();
                
                int s = substr.first, e = substr.second;
                for(;e < S.size(); e++){
                    if( T[i] == S[e] ){
                        que_tmp.push( {s, e+1} );
                        break;
                    }
                }
            }
            
            myque = que_tmp;
        }
        
        int min_size = INT_MAX;
        pair<int, int> w = {0,0};
        while( !myque.empty() ){
            pair<int, int> tmp = myque.front();
            myque.pop();
            
            int s = tmp.first, e = tmp.second;
            if( min_size > (e-s) ){
                min_size = e-s;
                w = tmp;
            }
        }
        
        if( w.second - w.first == 0 )
            return "";
        else
            return S.substr( w.first, min_size );
    }
    
private:
    queue<pair<int, int>> myque;
};
