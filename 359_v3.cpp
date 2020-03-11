class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        bool res;
        if( record.find(message) != record.end() ){
            if( record[message] <= timestamp - 10 ){
                res = true;
                record[message] = timestamp;
            }
            else{
                res = false;
            }
        }
        else{
            res = true;
            record[message] = timestamp;
        }
        
        return res;
    }
    
private:
    unordered_map<string, int> record;
};
