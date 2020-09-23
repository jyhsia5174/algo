// Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        for(int i = 0; i < 256; i++)
            Tcount[i] = count[i] = 0;
        
        for(int i = 0; i < t.size(); i++){
            Tcount[t[i]] ++;
        }
        
        int l = 0, r = 0;
        int minL = 1 << 30;
        int ll, rr;
        while(true){
            if(valid()){
                if( r - l < minL ){
                    ll = l;
                    rr = r;
                    minL = r - l;
                }
                
                count[s[l]] --;
                l++;
            }
            else{
                if( r == s.size() )
                    break;
                count[s[r]] ++;
                r++;
            }
        }
        
        if( minL != 1 << 30 )
            return s.substr(ll, minL);
        return "";
    }
private:
    int Tcount[256], count[256];
    
    bool valid(){
        for(int i = 0; i < 256; i++)
            if( count[i] < Tcount[i] )
                return false;
        return true;
    }
};
