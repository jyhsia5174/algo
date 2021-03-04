// 2 11m
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2   3   6
3   5   

20 / 2 = 10;
20 / 3 = 6;
20 / 6 = 3;

7   3   21 
6   5   30
   */
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL gcd(LL x, LL y){
    if(x < y) swap(x, y);
    if(y == 0) return x;

    return gcd(y, x % y);
}

LL lcm(LL x, LL y){
    return x * (y / gcd(x, y));
}

int main(){
    LL n, a, b, p, q;

    cin >> n >> a >> b >> p >> q;

    LL ablcm = lcm(a, b);
    LL acnt = n / a;
    LL bcnt = n / b;
    LL abcnt = n / ablcm;
    if( p > q )
        bcnt -= abcnt;
    else
        acnt -= abcnt;

    cout << acnt * p + bcnt * q << endl;
    return 0;
}
