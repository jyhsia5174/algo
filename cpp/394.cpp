// 394. Decode String
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string res;
        parse_es_seq( s, i, res);
        return res;
    }
    
    void parse_es_seq( string &s, int &i, string &res){
        while( i < s.size() ){
            if( s[i] == ']') break;
            parse_es( s, i, res);
        }
    }
    
    void parse_es( string &s, int &i, string &res){
        // read S
        int begin_i = i;
        while( special_char.count(s[i]) == 0 && i < s.size() ){
            res += s[i];
            i++;
        }
        
        if( i != begin_i )
            return;
        
        // read num [es_seq] S
        assert( int_char.count(s[i]) == 1 );
        int k = parse_num( s, i);
        i++; // read [
        string repeat_s;
        parse_es_seq( s, i, repeat_s);
        i++; // read ]
        for(int t = 0; t < k; t++)
            res += repeat_s;
        
        while( special_char.count(s[i]) == 0  && i < s.size()  ){
            res += s[i];
            i++;
        }
    }
    
    int parse_num( string &s, int &i){
        int res = 0;
        while( int_char.count(s[i]) ){
            res *= 10;
            res += s[i] - '0';
            i++;
        }
        return res;
    }
    
private:
    unordered_set<char> special_char {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '[', ']'};
    unordered_set<char> int_char {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
};
