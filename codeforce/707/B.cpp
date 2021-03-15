#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n, 0);
    vector<vector<int>> cover;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if( a > 0 ){
            int l = max(i - a + 1, 0);
            cover.push_back( {l, i} );
        }
    }
    sort(cover.begin(), cover.end());
    
    int x = 0;
    int mr = -1;
    for(int i = 0; i < n; i++){
        while(x < cover.size() && cover[x][0] <= i ){
            mr = max(mr, cover[x][1]);
            x++;
        }

        if( i <= mr )
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
