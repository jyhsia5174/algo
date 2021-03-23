// 56m 2
#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
}

LL floor(LL a, LL b){
    if( sgn(a) * sgn(b) < 0 ){
        if( a%b == 0 )
            return a/b;
        return a/b-1;
    }
    return a / b;
}

LL ceil(LL a, LL b){
    if( sgn(a)*sgn(b) < 0 )
        return a/b;
    if( a%b == 0 )
        return a/b;
    return a/b+1;
}

// gcd = a*x + b*y
LL gcd(LL a, LL b, LL &x, LL &y){
    if( b == 0 ){
        x = 1;
        y = 0;
        return a;
    }

    LL g = gcd( b, a%b, x, y);
    /* 
    g = b*x + (a%b)*y
    g = b*x + (a - (a/b)b) * y
    g = a*y + b*( x - (a/b)y )
    */
    LL xx = y;
    LL yy = x - (a/b) * y;
    x = xx;
    y = yy;
    return g;
}

int main(){
    LL a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

    L = max( 0ll, ceil(L-b1, a1) );
    R = floor(R-b1, a1);

    if( L > R ){
        cout << 0 << endl;
        return 0;
    }

    LL x, y, g, c;
    c = b2 - b1;
    g = gcd(a1, a2, x, y);

    if( c % g != 0 ){
        cout << 0 << endl;
        return 0;
    }

    LL xcg = x*c/g;
    L = ceil((L-xcg), a2/g);
    R = floor((R-xcg), a2/g);
    LL ycg = y*c/g;
    L = max( L, ceil(ycg, a1/g) );

    if( L <= R )
        cout << R - L + 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
