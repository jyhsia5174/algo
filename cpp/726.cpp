// 726. Number of Atoms
class Solution {
public:
    string countOfAtoms(string F) {
        vector<unordered_map<string, int>> L_count;
        L_count.resize(1);
        
        string name;
        int num;
        int level = 0;
        int idx = 0;
        while( idx < F.size() ){
            int next_type = peek( F[idx] );
            switch( next_type ){
                case 0:
                    idx++;
                    level++;
                    L_count.resize(level+1);
                    break;
                case 1:
                    idx++;
                    num = parse_num( F, idx);;
                    
                    for(auto &[name, count]: L_count[level])
                        L_count[level-1][name] += count * num;
                    L_count.pop_back();
                    level--;
                    break;
                case 2:
                    name = parse_name(F, idx);
                    num = parse_num(F, idx);
                    L_count[level][name] += num;
                    break;
                case 3:
                default:
                    return "Parsing Error";
            }
        }
        
        vector<pair<string, int>> res;
        for(auto &[name, count]: L_count[0])
            res.push_back( {name, count} );
        sort( res.begin(), res.end() );
        
        string ans;
        for(auto &[name, count]: res){
            ans += name;
            if( count != 1 )
                ans += to_string(count);
        }
        return ans;
    }
    
    int peek(char c){
        if( c == '(' ){
            return 0;
        }
        else if( c == ')' ){
            return 1;
        }
        else if( isalpha(c) ){
            return 2;
        }
        else if( isdigit(c) ){
            return 3;
        }
        cerr << "no match" << endl;
        exit(1);
    }
    
    string parse_name(const string &s, int &idx){
        string res (s, idx, 1) ;
        idx++;
        while(idx < s.size() &&
              isalpha(s[idx]) && islower(s[idx]) ){
            res += s[idx];
            idx++;
        }
        return res;
    }
    
    int parse_num(const string &s, int &idx){
        if( idx >= s.size() || !isdigit(s[idx]) )
            return 1;
        string res (s, idx, 1) ;
        idx++;
        while(idx < s.size() && isdigit(s[idx])){
            res += s[idx];
            idx++;
        }
        return stoi( res );
    }
};
