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
