class StreamChecker {
public:
    
    typedef unsigned long long ull;
    const ull B = 1000000007;
    
    ull T[2001];
    unordered_set<ull> W;
    vector<int> sz;
    ull streamH[2000];
    
    int p = 0;
    int pre_letter[2000];
    
    StreamChecker(vector<string>& words) {
        std::ios::sync_with_stdio(false);
        T[0] = 1;
        for(int i = 1; i < 2001; i++)
            T[i] = T[i-1] * B;
        
        for( auto &s: words ){
            ull ah = 0;
            for(int i = 0; i < s.size(); i++)
                ah = ah * B + s[i];
            W.insert(ah);
            sz.push_back(s.size());
        }
        
        sort(sz.begin(), sz.end());
        auto last = unique(sz.begin(), sz.end());
        sz.erase(last, sz.end());
        
        for(auto it = sz.begin(); it != sz.end() ; it++){
            int i = (*it) - 1;
            streamH[i] = pre_letter[i] = 0;
        }
        
    }
    
    bool query(char letter) {
        bool res = false;
        
        for(auto it = sz.begin(); it != sz.end() ; it++){
            int i = (*it) - 1;
            ull &t = T[i];
            streamH[i] = (streamH[i] - pre_letter[(p-(i+1)+2000)%2000] * t) * B + letter;
            
            if( W.find(streamH[i]) != W.end() )
                res = true;
        }
        
        pre_letter[p] = letter;
        p = (p+1) % 2000;
        
        return res;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

