bool cmp(const string &a, const string &b){
    return a.size() > b.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& W) {
    
        //sort(W.begin(), W.end(), cmp);
        
        for(int i = 0; i < W.size(); i++){
            level[W[i].size()].push_back(i);
            H[i] = -1;
        }
        
        init_sc(W);
        
        int maxH = 0;
        for(int lv = 0; lv < 20; lv++){
            for(auto &i: level[lv]){
                if( H[i] != -1 ){
                    maxH = max<int>(maxH, H[i]);
                    continue;
                }
                
                H[i] = getH(lv, i, W);
                maxH = max<int>(maxH, H[i]);
                //cout << setw(10) << maxH << setw(10) << H[i] << endl;
            }
        }
        
        /*for(int i = 0; i < W.size(); i++){
            cout << setw(10) << W[i].size() << setw(10) << W[i] << setw(10) << H[i] << endl;
        }*/
        
        return maxH;
    }
    
private:
    unordered_set<string> sc[1002];  // Potentail successor
    vector<int> level[20];
    int  H[1002];
    
    int getH(int lv, int i, vector<string> &W){
        H[i] = 1;
        vector<int> &nlevel = level[lv+1];
        if( nlevel.size() == 0 )
            return H[i];
        
        for(auto &j: nlevel){
            if( H[j] == -1 )
                H[j] = getH(lv+1, j, W);
            
            unordered_set<string> &sc_j = sc[j];
            if( sc_j.find(W[i]) != sc_j.end() )
                H[i] = max( H[i], H[j] + 1);
        }
        
        return H[i];
    }
    
    void init_sc( vector<string>& W){
        string subs;
        for(int i = 0; i < W.size(); i++){
            string &s = W[i];
            if( s.size() < 2 )
                continue;
            
            for(int j = 0; j < s.size(); j++){
                subs = s.substr(0, j) + s.substr(j+1, s.size()-(j+1));
                sc[i].insert(subs);
            }
        }
    }
    
};
