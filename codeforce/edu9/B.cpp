// 17m
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> STR(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        STR[i] = val;
    }

    string grp;
    cin >> grp;

    LL Bscr = 0;
    for(int i = 0; i < n; i++)
        if( grp[i] == 'B' )
            Bscr += STR[i];
    
    LL ans = Bscr;
    LL head = 0, tail = 0;
    for(int i = 0; i < n; i++){
        head += ( grp[i] == 'A' ) ? STR[i] : -STR[i];
        tail += ( grp[n-1-i] == 'A' ) ? STR[n-1-i] : -STR[n-1-i];
        ans = max( ans, Bscr + head );
        ans = max( ans, Bscr + tail );
    }

    cout << ans << endl;
    return 0;
}
