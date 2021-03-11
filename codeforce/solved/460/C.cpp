#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> S;

int count(string row, int k){
    int ans = 0;
    row += "*";
    int curLen = 0;
    for(int i = 0; i < row.size(); i++){
        if( row[i] == '.' ){
            curLen++;
        }
        else{
            if( curLen >= k ){
                ans += curLen - k + 1;
            }
            curLen = 0;
        }
    }

    return ans;
}

int main(){
    cin >> n >> m >> k;
    S.resize(n);
    for(int i = 0; i < n; i++)
        cin >> S[i];

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += count(S[i], k);

    if( k == 1 ){
        cout << ans << endl;
        return 0;
    }

    for(int j = 0; j < m; j++){
        string col = "";
        for(int i = 0; i < n; i++){
            col.push_back( S[i][j] );
        }
        ans += count( col, k );
    }

    cout << ans << endl;

    return 0;
}
