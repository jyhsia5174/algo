// 20m 1
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<double> x;
    vector<double> y;

    int a, b;
    for(int i = 0; i < 2*n; i++){
        cin >> a >> b;
        if( a == 0 ){
            b = (b > 0)? b : -b;
            y.push_back(b);
        }
        else{
            a = (a > 0)? a: -a;
            x.push_back(a);
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += sqrt( x[i]*x[i] + y[i]*y[i] );
    }

    cout << setprecision(20) << ans << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
