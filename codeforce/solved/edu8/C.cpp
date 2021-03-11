#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int i = 0;
    string ans = "";
    while( k >= 0 && i < n ){
        int c = s[i] - 'a';
        int val = max(c,  25 - c);
        if( val <= k ){
            if( c < 25 - c)
                ans.push_back( c+val+'a' );
            else
                ans.push_back( c-val+'a' );
            k -= val;
        }
        else{
            if( c + k < 26 )
                ans.push_back( c+k+'a' );
            else
                ans.push_back( c-k+'a' );
            k -= k;
        }
        i++;
    }

    if( k <= 0 )
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}
