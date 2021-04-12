class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        hi.push(num);
        lo.push(hi.top());
        hi.pop();
        
        while( hi.size() < lo.size() ){
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        if( lo.size() == hi.size() ){
            return ( lo.top() + hi.top() ) / 2.0;
        }
        else{
            return hi.top();
        }
    }
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, std::greater<int> > hi;
};
