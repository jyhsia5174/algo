#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL ceil(LL a, LL b);
LL floor(LL a, LL b){
    if( b < 0 )
        return floor(-a, -b);
    if( a < 0 )
        return -ceil(-a, b);
    return a / b;
}
LL ceil(LL a, LL b){
    if( b < 0 )
        return ceil(-a, -b);
    if( a < 0 )
        return -floor(-a, b);
    return (a+b-1)/b;
}

LL gcd(LL a, LL b, LL &x, LL &y){
    if( b == 0 ){
        x = 1;
        y = 0;
        return a;
    }
    LL gcdab = gcd(b, a%b, x, y);
    LL xx = y;
    LL yy = x - (a/b) * y;
    x = xx;
    y = yy;
    return gcdab;
}

int main(){
    LL a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;

    l = max(0LL, ceil(l-b1, a1));
    r = floor(r-b1, a1);

    if( l > r ){
        cout << 0 << endl;
        return 0;
    }

    LL g, x, y;
    g = gcd(a1, -a2, x, y);
    LL c = b2 - b1;
    if( c % g ){
        cout << 0 << endl;
        return 0;
    }

    if( g < 0 ){
        g = -g;
        x *= -1;
        y *= -1;
    }

    LL ll = ceil(r*g - x*c, -a2);
    LL rr = floor(l*g - x*c, -a2);
    rr = min( rr, floor(y*c, a1) );

    LL ans = max(0LL, rr - ll + 1);
    cout << ans << endl;
    return 0;
}
