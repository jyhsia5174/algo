#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> box[1001];

void solve(){
    vector<int> sol;
    for(int i = 0; i < 1001; i++){
        sort(box[i].begin(), box[i].end());
        if(i%2)
            reverse(box[i].begin(), box[i].end());
        for(auto &v: box[i])
            sol.push_back( v[1] );
    }
    for(auto &v: sol)
        cout << v << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        box[x/1000].push_back({y, i+1});
    }

    solve();
    return 0;
}
