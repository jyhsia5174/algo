// 12m 2
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> res;
    for(int i = 2; i <= n; i++){
        if( res.size() == k-1 ) break;
        while(n % i == 0){
            if( res.size() == k-1 ) break;
            res.push_back(i);
            n /= i;
        }
    }

    if( (n == 1) || (res.size() < k-1) ){
        cout << -1 << endl;
        return;
    }

    res.push_back(n);

    for(auto &v: res)
        cout << v << " ";
    cout << endl;
}

int main(){
    solve();
}
