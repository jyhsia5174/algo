// 953. Verifying an Alien Dictionary
bool table[26][26];

void init_cmp_table(const string &s){
    for(int i = 0; i < 26; i++){
        for(int j = i ; j < 26; j++){
            int a = s[i] - 'a';
            int b = s[j] - 'a';
            table[a][b] = true;
            table[b][a] = false;
        }
    }
}
    
bool cmp(const string &l, const string & r){
    int i = 0;
    while( i < l.size() && i < r.size() ){
        if( l[i] != r[i] ) return table[l[i]-'a'][r[i]-'a'];
        i++;
    }
    if( l.size() <= r.size() ) return true;
    return false;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        init_cmp_table(order);
        vector<string> s_copy( words.begin(), words.end());
        sort( s_copy.begin(), s_copy.end(), cmp );
        
        for(int i = 0; i < words.size(); i++)
            if( s_copy[i] != words[i] )
                return false;
        return true;
    }
};
