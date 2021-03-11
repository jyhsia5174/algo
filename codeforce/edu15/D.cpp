// 26m 2
// LL rep = d / k not d / carP
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    LL d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    if( d <= k ){
        cout << d * a << endl;
        return 0;
    }
    
    LL T = k * a;
    d -= k;
    
    LL carP = t + k*a;
    if( carP >= k*b ){
        cout << T + d*b << endl;
        return 0;
    }

    LL rep = d / k;
    T += rep * carP;
    d -= rep * k;

    if( d > 0 ){
        LL walkt = d * b;
        LL cart = d * a + t;
        T += min( walkt, cart );
    }

    cout << T << endl;
    return 0;
}
