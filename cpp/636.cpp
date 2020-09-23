// 636. Exclusive Time of Functions
class status{
public:
    int id;
    int type; // 0: st 1:end
    int t;
    status (string &s){
        string::size_type pos = 0;
        
        size_t start = 0;
        size_t end = s.find(":");
        vector<string> tokens;
        while( end != string::npos ){
            tokens.push_back( s.substr(start, end - start) );
            start = end + 1;
            end = s.find(":", start);
        }
        tokens.push_back( s.substr(start, end) );
        id = stoi( tokens[0] );
        if( tokens[1] == "start" ) type = 0;
        else type = 1;
        t = stoi( tokens[2] );
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans;
        ans.resize(n, 0);
        
        vector<status> L;
        for(auto &s: logs)
            L.emplace_back( s );
        
        stack<pair<int, int>> open_thread;
        unordered_set<int> closed_set;
        
        sort(L.begin(), L.end(), [](const status &a, const status &b){ return a.t < b.t; });
        
        for(auto &S: L){
            if( S.type == 0 ){
                if( !open_thread.empty() ){
                    auto &thread = open_thread.top();
                    ans[thread.first] += (S.t - thread.second);
                    thread.second = S.t;
                }
                open_thread.push( {S.id, S.t} );
                //closed_set.erase( S.id );
            }
            else{
                if( (!open_thread.empty()) && S.id ==  open_thread.top().first ){
                    auto thread = open_thread.top();
                    open_thread.pop();
                    ans[thread.first] += (S.t - thread.second) + 1;
                    //while( (!open_thread.empty()) && closed_set.count(open_thread.top().first) == 1 ) open_thread.pop();
                    if( !open_thread.empty() ) 
                    {   
                        auto &thread2 = open_thread.top();
                        thread2.second = S.t+1;
                    }
                }
                closed_set.insert(S.id);
            }
        }
        
        return ans;
    }   
};
