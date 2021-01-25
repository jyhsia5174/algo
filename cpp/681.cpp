/*
681. Next Closest Time
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Closest Time.
Memory Usage: 6.1 MB, less than 86.79% of C++ online submissions for Next Closest Time.
*/
class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<char> S{time[0],time[1], time[3], time[4]};
        
        int t1 = calc_time( stoi(time.substr(0,2)), stoi(time.substr(3,2)) );
        int diff = 2<<29;
        string res = "";
        for(auto x1: S){
            for(auto x2: S){
                for(auto y1: S){
                    for(auto y2: S){
                        string xx {x1, x2};
                        string yy {y1, y2};
                        if( !valid( xx, yy ) )
                            continue;
                        int t2 = calc_time( stoi(xx), stoi(yy) );
                        int ndiff;
                        if( t2 > t1 )
                            ndiff = t2 - t1;
                        else
                            ndiff = (t2 + 24 * 60) - t1;
                        if( ndiff < diff ){
                            diff = ndiff;
                            res = xx + ":" + yy;
                        }
                    }
                }
            }
        }
        
        return res;
    }
    
    int calc_time(int x, int y){
        return x*60 + y;
    }
    
    bool valid( const string &xx, const string &yy ){
        int x = stoi(xx);
        int y = stoi(yy);
        if( x > 24 )
            return false;
        if( y > 59)
            return false;
        return true;
    }
};
