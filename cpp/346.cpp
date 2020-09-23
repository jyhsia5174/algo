// Moving Average from Data Stream
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        count = 0;
        K = size;
    }
    
    double next(int val) {
        if( count < K ){
            sum += val;
            Q.push(val);
            count++;
            return sum / count;
        }
        
        sum -= Q.front();
        Q.pop();
        sum += val;
        Q.push(val);
        return sum / K;
    }
private:
    queue<int> Q;
    double sum;
    int count, K;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
