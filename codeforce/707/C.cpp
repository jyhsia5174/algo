#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int w, int z){
    return x != w && x != z && y != w && y != z;
}

int main(){
    int n;
    cin >>n;
    vector<int> A(n);

    for(auto &v: A)
        cin >> v;

    vector<vector<pair<int, int>>> dp(5e6+1);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = A[i] + A[j];
            for(auto &v: dp[sum]){
                int v1 = v.first;
                int v2 = v.second;
                if( check(i, j, v1, v2) ){
                    cout << "YES" << endl;
                    printf( "%d %d %d %d\n", i+1, j+1, v1+1, v2+1);
                    return 0;
                }
            }
            dp[sum].push_back( {i, j} );
            if( dp[sum].size() >= 4 ){
                cout << "YES" << endl;
                auto &p1 = dp[sum][0];
                auto &p2 = dp[sum][1];
                if( p1.first == p2.first ){
                    for(auto p: dp[sum])
                        cout << p.second + 1 << " ";
                    cout << endl;
                }
                else{
                    for(auto p: dp[sum])
                        cout << p.first+1 << " ";
                    cout << endl;
                }
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
