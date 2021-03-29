// 1 120
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
LL xs, ys, xe, ye;
LL spd, t;
LL vx, vy, wx, wy;

LL dist(LL x, LL y, LL xx, LL yy){
    return (x - xx)^2 + (y - yy)^2;
}

void solve(){
    xe -= xs;
    ye -= ys;

    double lo = 0;
    double hi = 1e9;
    while( (hi - lo) / max(1.0,hi) > 1e-6  ){
        double mi = lo + (hi - lo) / 2;
        double dx = 0, dy = 0;
        if( mi < t ){
            dx = mi * vx;
            dy = mi * vy;
        }
        else{
            dx = t * vx + (mi - t) * wx;
            dy = t * vy + (mi - t) * wy;
        }

        dx -= xe;
        dy -= ye;
        if(sqrt( dx * dx + dy * dy ) <= mi * spd){
            hi = mi;
        }
        else{
            lo = mi;
        }
    }
    cout << setprecision(20) << hi << endl;
}

int main(){
    cin >> xs >> ys >> xe >> ye;
    cin >> spd >> t;
    cin >> vx >> vy >> wx >> wy;
    solve();
    return 0;
}
