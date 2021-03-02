// 1 11m
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;

    char pre = s[0];
    for(int i = 1; i < s.size(); i++){
        if( s[i] == pre ){
            for(int j = 0; j < 26; j++){
                char cj = 'a' + j;
                if( cj == s[i-1] )
                    continue;
                if( i+1 < s.size() && cj == s[i+1] )
                    continue;
                
                s[i] = cj;
                break;
            }
        }
        pre = s[i];
    }

    cout << s << endl;
    return 0;
}
