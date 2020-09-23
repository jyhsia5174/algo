int *sarank, *tmp, *sa;
int k, n;
    
bool compare_sa(int i, int j){
    if( sarank[i] != sarank[j] ){
        return sarank[i] < sarank[j];
    }
    else{
        int ri = (i + k <= n) ? sarank[i+k] : -1;
        int rj = (j + k <= n) ? sarank[j+k] : -1;
        return ri < rj;
    }
}

class Solution {
public:
    string lastSubstring(string s) {
        n = s.size();
        k = 1;
        sarank = new int[n+1];
        tmp = new int[n+1];
        sa = new int[n+1];
        
        construct_sa( s, sa );
        string ans = s.substr(sa[s.size()], s.size() - sa[s.size()]);
        
        delete[] sarank;
        delete[] tmp;
        delete[] sa;
            
        return ans;
    }
    
private:
    
    
    void construct_sa( string &s, int *sa){
        
        for(int i = 0; i <=n ; i++){
            sa[i] = i;
            sarank[i] = i < n ? s[i] : -1;
        }
        
        for(k=1; k <= n; k*=2){
            sort(sa, sa+n+1, compare_sa);
            
            cout << 2*k << endl;
            /*
            for(int i = 0; i <= n; i++){
                cout << s.substr(sa[i], min(2*k, n) - sa[i]) << endl;
            }
            cout << "=====================" << endl;
            */
            
            tmp[sa[0]] = 0;
            for(int i = 1; i <= n; i++){
                tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
            }
            
            for(int i = 0; i <= n; i++){
                sarank[i] = tmp[i];
            }
        }
    }
};
