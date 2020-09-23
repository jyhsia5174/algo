class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if( !check(p1,p2,p3,p4) ) return false;
        if( !check(p2,p1,p3,p4) ) return false;
        if( !check(p3,p2,p1,p4) ) return false;
        if( !check(p4,p2,p3,p1) ) return false;
        return true;
    }
    
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        double d1 = dist(p1, p2);
        double d2 = dist(p1, p3);
        double d3 = dist(p1, p4);
        
        if( d1 <= 0 || d2 <= 0 || d3 <= 0) return false;
        
        if( d1 == d2 )
            return is_right_angle(p1, p2, p3);
        else if( d1 == d3 )
            return is_right_angle(p1, p2, p4);
        else if( d2 == d3 )
            return is_right_angle(p1, p3, p4);
        else
            return false;
    }
    
    double dist( vector<int>& p1, vector<int>& p2 ){
        double x = p1[0] - p2[0];
        double y = p1[1] - p2[1];
        return x*x + y*y;
    }
    
    bool is_right_angle(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int x1 = p2[0] - p1[0];
        int y1 = p2[1] - p1[1];
        int x2 = p3[0] - p1[0];
        int y2 = p3[1] - p1[1];
        
        if( x1 * x2 + y1 * y2 == 0 )
            return true;
        return false;
    }
};
