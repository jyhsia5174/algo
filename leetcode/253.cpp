/*
253. Meeting Rooms II
Runtime: 12 ms, faster than 99.34% of C++ online submissions for Meeting Rooms II.
Memory Usage: 11.7 MB, less than 98.90% of C++ online submissions for Meeting Rooms II.
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), [](const vector<int> &l, const vector<int> &r){
            return l[0] < r[0];
        });
        
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> Q;
        for(auto &v: I){
            int st = v[0];
            int ed = v[1];
            
            while( !Q.empty() && Q.top() <= st )
                Q.pop();
            
            Q.push( ed );
            res = max( res, (int) Q.size() );
        }
        
        return res;
    }
};


// Meeting Rooms II
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        vector<pair<int, int>> A;
        for(int i = 0; i < intervals.size(); i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            A.push_back( {s, 0} );
            A.push_back( {e, 1} );
        }
        
        sort(A.begin(), A.end());
        
        int maxRoom = 0;
        
        int i = 0;
        int t = A[0].first;
        int room = 0;
        while( i < A.size() ){
            if( t != A[i].first ){
                maxRoom = max(maxRoom, room);
                t = A[i].first;
            }
            
            if( A[i].second == 0 ){
                room ++;
            }
            else{
                room --;
            }
            
            i++;
        }
        
        return maxRoom;
    }
};
