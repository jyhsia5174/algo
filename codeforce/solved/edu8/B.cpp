#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    LL ans = 0;
    int val = 0;
    for(int i = 0; i < s.size(); i++){
        val = (val * 10 + s[i] - '0') % 100;

        if( val % 4 == 0 && i >= 1 ){
            ans += i;
        }

        if( (s[i] - '0') % 4 == 0 )
            ans ++;
    }

    cout << ans << endl;
    return 0;
}
