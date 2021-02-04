/*
8. String to Integer (atoi)
*/
class Solution {
public:
    int myAtoi(string s) {
        if( s.size() == 0 )
            return 0;
        
        // trim leading ' '
        int idx = parse_white_space(s, 0);
        if( idx == -1 )
            return 0;
        
        // parse sign
        int sign;
        idx = parse_sign(s, idx, sign);
        if( idx == -1 )
            return 0;
        
        // parse digit
        string digit;
        idx = parse_digit(s, idx, digit);
        
        return convert( sign, digit );
    }
    
    int convert(int sign, const string &digit){
        unsigned int one = 1;
        unsigned int neg = one << 31;
        unsigned int pos = (one << 31) - 1;
        
        string negS = to_string(neg);
        string posS = to_string(pos);
        
        int nonzero = digit.find_first_not_of('0');
        if( nonzero == string::npos )
            return 0;
        string trimDigit = digit.substr(nonzero, digit.size() - nonzero);
        
        if( sign == 1 && greater(trimDigit, posS) )
                return pos;
        
        if( sign == -1 && greater(trimDigit, negS) )
                return -neg;

        unsigned int val = 0;
        for(int i = 0; i < trimDigit.size(); i++){
            val *= 10;
            val += (trimDigit[i] - '0');
        }
        
        return sign*val;
    }
    
    bool greater(const string &s1, const string &s2){
        if( s1.size() > s2.size() )
            return true;
        if( s1.size() < s2.size() )
            return false;
        
        for(int i = 0; i < s1.size(); i++){
            if( s1[i] > s2[i] )
                return true;
            else if( s1[i] < s2[i] )
                return false;
        }
        
        return false;
    }
    
    int parse_digit(const string &s, int idx, string &digit){
        while( idx < s.size() && isdigit(s[idx]) ){
            digit.push_back( s[idx] );
            idx++;
        }
        
        if( idx >= s.size() )
            return -1;
        return idx;
    }
    
    int parse_white_space(const string &s, int idx){
        while( idx < s.size() && s[idx] == ' ' )
            idx++;
        
        if( idx >= s.size() )
            return -1;
        return idx;
    }
    
    int parse_sign(const string &s, int idx, int &sign){
        if( s[idx] == '-' ){
            sign = -1;
            idx++;
        }
        else if( s[idx] == '+' ){
            sign = 1;
            idx++;
        }
        else{
            sign = 1;
        }
        
        if( idx >= s.size() )
            return -1;
        return idx;
    }
};
