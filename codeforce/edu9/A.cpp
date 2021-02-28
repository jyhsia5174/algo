/*
19m
0   1   2   3   4   5   6   7
0   0   1   1   2   2   3   3   ...

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL n, p;
    cin >> n >> p;

    string s;
    vector<bool> isPlus(n, true);
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.size() == 4)
            isPlus[n - 1 - i] = false;
    }

    LL ans = 0;
    LL count = 0;
    for(int i = 0; i < n; i++){
        if( isPlus[i] ){
            ans += count * p + 0.5 * p;
            count = count * 2 + 1;
        }
        else{
            ans += count * p;
            count = count * 2;
        }
    }

    cout << ans << endl;
    return 0;
}
