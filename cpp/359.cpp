typedef pair<int, string> P;

class mycmp{
public:
    bool operator() (const P &a, const P &b ) const{
        return a.first > b.first;
    }
};

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        while( !pq.empty() ){
            const P &tmp = pq.top();
            if( tmp.first > timestamp - 10)
                break;
            cnt.erase( tmp.second );
            pq.pop();
        }
        
        bool res;
        if( cnt.find(message) != cnt.end() ){
            res = false;
        }
        else{
            res = true;
            cnt.insert( message );
            pq.push( {timestamp, message} );
        }
        
        return res;
    }
    
private:
    
    priority_queue<P, vector<P>, mycmp> pq;
    unordered_set<string> cnt;
};
