// 937. Reorder Data in Log Files
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, string> l_log;
        queue<string> d_log;
        
        for(auto &s: logs){
            if( is_letter_log(s) ){
                l_log[s.substr(s.find(" ")+1, s.size()-(s.find(" ")+1)) + s.substr(0, s.find(" "))] = s;
                cout << s << endl;
            }
            else{
                d_log.push(s);
            }
        }
        
        vector<string> ans;
        cout << l_log.size() << endl;
        for(auto &ss: l_log)
            ans.push_back( ss.second );
        while( !d_log.empty() ){
            ans.push_back( d_log.front() );
            d_log.pop();
        }
                
        return ans;
    }
    
    bool is_letter_log(string &s){
        size_t start = 0;
        size_t end = s.find(" ");
        start = end+1;
        end = s.find(" ", start);
        if( end == string::npos ) end = s.size();
        for(int i = start; i < end; i++){
            if( !isalpha(s[i]) ) return false;
        }
        return true;
    }
};
