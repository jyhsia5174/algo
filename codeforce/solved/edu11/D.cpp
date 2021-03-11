// 40m
#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    int n;
    cin >> n;

    vector<vector<LL>> A(n, {0, 0});
    for(auto &v: A)
        cin >> v[0] >> v[1];

    LL ans = 0;
    unordered_map<LL, LL> M;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            LL x = A[i][0] - A[j][0];
            LL y = A[i][1] - A[j][1];
            if( x < 0 ){
                x = -x;
                y = -y;
            }
            else if(x == 0 && y < 0){
                y = -y;
            }

            LL hs = (x+1) * (3e9) + (1e9 + y);
            if( M.find(hs) != M.end() )
                ans +=  M[hs];
            M[hs]++;
        }
    }

    cout << ans / 2 << endl;
}
