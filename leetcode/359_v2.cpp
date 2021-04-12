typedef pair<int, string> P;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        while( !Q.empty() ){
            const P &tmp = Q.front();
            if( tmp.first > timestamp - 10)
                break;
            cnt.erase( tmp.second );
            Q.pop();
        }
        
        bool res;
        if( cnt.find(message) != cnt.end() ){
            res = false;
        }
        else{
            res = true;
            cnt.insert( message );
            Q.push( {timestamp, message} );
        }
        
        return res;
    }
    
private:
    
    queue<P> Q;
    unordered_set<string> cnt;
};
