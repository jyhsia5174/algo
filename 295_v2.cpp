// Two heap

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if( lo.size() != 0 && hi.size() != 0){
            if( num < lo.top() )
                lo.push(num);
            else
                hi.push(num);
        }
        else if( lo.size() == 0 ){
            hi.push(num);
        }
        else{
            lo.push(num);
        }
        
        while( abs( (int) (lo.size() - hi.size()) ) > 1 ){
            if( lo.size() > hi.size() ){
                hi.push(lo.top());
                lo.pop();
            }
            else{
                lo.push( hi.top() );
                hi.pop();
            }
        }
    }
    
    double findMedian() {
        if( lo.size() == hi.size() ){
            return ( lo.top() + hi.top() ) / 2.0;
        }
        else if( lo.size() > hi.size() ){
            return lo.top();
        }
        else{
            return hi.top();
        }
    }
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, std::greater<int> > hi;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
