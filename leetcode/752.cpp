class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        for( int i = 0; i < 10000; i++ ){
            dp[i] = -1;
            visited[i] = 0;
        }
        dp[stoi(target)] = 0;
        
        for(const string &block: deadends )
            dead.insert( stoi( block ) );
        
        
        queue<string> myque;
        myque.push( target );
        visited[ stoi(target) ] = 1;
        
        int i = 1;
        while( ! myque.empty() ){
            queue<string> tmp;
            
            while( !myque.empty() ){
                string pos = myque.front();
                myque.pop();
                
                for(auto &d: dirs){
                    string next_pos = get_next_pos( pos, d );
                    
                    if( !is_possible( next_pos ) || visited[stoi(next_pos)] == 1 )
                        continue;
                    
                    dp[ stoi(next_pos) ] = i;
                    visited[ stoi(next_pos) ] = 1;
                    tmp.push( next_pos );
                }
            }
            
            myque = tmp;
            i++;
        }
        
        
        return dp[0];
    }
    
private:
    unordered_set<int> dead;
    vector<vector<int>> dirs= { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, \
                              {-1, 0, 0, 0}, {0, -1, 0, 0}, {0, 0, -1, 0}, {0, 0, 0, -1} };
    int dp[10000];
    int visited[10000];
    
    bool is_possible( const string & pos ){
        if( dead.find( stoi(pos) ) == dead.end() )
            return true;
        else 
            return false;
    }
    
    string get_next_pos(const string &cur_pos, const vector<int> &d){
        string next_pos = cur_pos;
        for(int i = 0; i < 4; i++){
            char num = cur_pos[i];
            if( d[i] == 1 )
                next_pos[i] = next( num );
            else if(d[i] == -1)
                next_pos[i] = prev( (char) cur_pos[i] );
            else
                continue;
        }
        return next_pos;
    }
    
    char next(const char c ) {
        int c_next = ( int ( c - '0') + 1 ) % 10;
        return (char) c_next + '0';
    }
    
    char prev(const char c ) {
        int c_prev = ( int ( c - '0') - 1  + 10) % 10;
        return (char) c_prev + '0' ;
    }
};
