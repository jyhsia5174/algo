// 1 25m
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

vector<int> prime;

int gcd(int x, int y){
    if( x < y ) swap(x, y);

    if( y == 0 )
        return x;
    return gcd(y, x % y);
}

LL coprime(LL x, LL y, LL div){
    LL lcm = x * (y / div);
    for(auto &p: prime)
        if( lcm % p != 0 )
            return p;
    return -1;
}

void init_prime(){
    prime.push_back(2);
    for(int i = 3; i < 4e4; i++){
        bool isPrime = true;
        for(auto &p: prime){
            if( i < p * p )
                break;
            if( i % p == 0 ){
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            prime.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A)
        cin >> a;

    init_prime();

    vector<int> res;
    for(int i = 0; i < n-1; i++){
        int div = gcd(A[i], A[i+1]);
        res.push_back(A[i]);
        if(div != 1){
            res.push_back( coprime(A[i], A[i+1], div) );
        }
    }
    res.push_back( A[n-1] );

    cout << res.size() - A.size() << endl;
    for(auto &v: res)
        cout << v << " ";

    return 0;
}
