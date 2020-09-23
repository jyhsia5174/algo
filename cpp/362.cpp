class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        for(int i = 0; i < 300; i++)
            cnt[i] = 0;
        
        s = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        for(int i = 0; s + 299 < timestamp && i < 300; i++, s++){
            cnt[s%300] = 0;
        }
        s = timestamp > 299 ? ( timestamp - 299 ) : s;
        
        cnt[timestamp%300] += 1;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        for(int i = 0; s + 299 < timestamp && i < 300; i++, s++){
            cnt[s%300] = 0;
        }
        s = timestamp > 299 ? ( timestamp - 299 ) : s;
        
        int sum = 0; 
        for(int i = 0; i < 300; i++)
            sum += cnt[(s+i)%300];
        
        return sum;
    }

private:
    int cnt[300];
    int s = 0; // [ i%300 for i in [t, t+300) ] range list
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
