// 1h 1
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    while(k>3){
        cout << 1 << " ";
        n--; k--;
    }

    int a = (n & -n);
    int b, c;
    if( a == n ){
        b = a >> 2;
        c = a >> 2;
        a >>= 1;
        printf("%d %d %d\n", a, b, c);
    }
    else{
        int rem = n - a;
        b = rem >> 1;
        c = rem >> 1;
        printf("%d %d %d\n", a, b, c);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
