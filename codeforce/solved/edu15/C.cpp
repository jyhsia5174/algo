// 14m 2
// y == m not n
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    
    vector<int> C(n), T(m);
    for(auto &v: C) cin >> v;
    for(auto &v: T) cin >> v;

    int r = 0;
    for(auto &x: C){
        int y = lower_bound(T.begin(), T.end(), x) - T.begin();
        
        int rx;
        if( y == m )
            rx = x - T[y-1];
        else if( y == 0 )
            rx = T[0] - x;
        else
            rx = min( T[y]-x, x-T[y-1] );
        
        r = max(rx, r);
    }

    cout << r << endl;
    return 0;
}
