// 621. Task Scheduler
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq;
        freq.resize(26, 0);
        for( auto &c: tasks )
            freq[c - 'A']++;
        
        sort(freq.begin(), freq.end());
        int f_max = freq[25];
        int idle = (f_max-1)*n;
        for(int i = 24; i >= 0 && idle > 0; i--)
            idle -= min( f_max-1, freq[i] );
        
        idle = max(0, idle);        
        return idle + tasks.size();
    }
};
