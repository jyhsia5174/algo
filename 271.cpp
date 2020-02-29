class Codec {
public:
    
    typedef unsigned int uint;

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        
        for(string &s: strs){
            res += LToString( s.size() );
            res += s;
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int N = s.size();
        vector<string> strs;
        
        int i = 0;
        while( i < N ){
            int L = stringToL( s.substr(i, 4) );
            i += 4;
            strs.push_back( s.substr(i, L) );
            i += L;
        }
        
        return strs;
    }
    
    string LToString( int L ){
        char bits[4];
        for(int i = 3; i > -1; i--){
            bits[3-i] = (unsigned char) ( (L >> (i*8)) & 0xff );
        }
        return string(bits,4);
    }
    
    int stringToL( string s ){
        int res = 0;
        for(unsigned char c: s){
            res = (res << 8) + (int) c;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
