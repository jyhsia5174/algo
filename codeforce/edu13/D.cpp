// 20 150
/*

0   x

1   Ax + B

2   AAx + AB + B

3   AAAx + AAB + AB + B
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL p = 1e9 + 7;

LL mult(LL x, LL y){
    return (x * y) % p;
}

LL add(LL x, LL y){
    return (x + y) % p;
}

int main(){
    LL A, B, n, x;
    cin >> A >> B >> n >> x;
    while(n){
        if(n&1){
            x = add(mult(x, A), B);
        }
        n>>=1;
        B = add(mult(A, B), B);
        A = mult(A, A);
    }
    cout << x << endl;
    return 0;
}

/*

LL dec(LL x, LL y){
    return ((x - y) % p + p) % p;
}

LL power(LL base, LL e){
    LL res = 1;
    while( e > 0 ){
        if( e & 1 )
            res = mult(res, base);
        base = mult(base, base);
        e >>= 1;
    }

    return res; 
}

int main(){
    LL A, B, n, x;

    cin >> A >> B >> n >> x;

    if( n == 0 ){
        cout << x << endl;
    }
    else if( A == 1 ){
        LL BAA = mult(n%p, B);
        LL Anx = x;
        cout << add(Anx, BAA) << endl;
    }
    else{
        LL C = A-1;
        LL Cinv = power(C, p-2);
        LL An = power(A, n);
        LL D =  dec(An, 1);
        LL BAA = mult(B, mult(D, Cinv));
        LL Anx = mult(An, x);
        cout << add( Anx, BAA ) << endl;
    }

    return 0;
}
*/
