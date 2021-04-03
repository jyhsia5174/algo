#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n;
vector<vector<LL>> A;

void solve(){
    sort(A.begin(), A.end());

    LL x = 0, base = 1, tolinv = 0;
    while( base < 1e9 ){
        LL l = 0, inv = 0, ninv = 0;
        while( l < n ){
            LL r = l;
            vector<LL> zero, one;
            while(r < n && A[l][0]/(base<<1) == A[r][0]/(base<<1) ){ // bug1: r < n
                if( (A[r][0] & base) == 0 ) zero.push_back(A[r][1]); // bug2: A[r][0] == base or 0 not 1 or 0
                else one.push_back(A[r][1]);
                r++;
            }
            sort(zero.begin(), zero.end()); // bug3: zero may not be sorted
            for(auto &v: one){
                LL x = upper_bound(zero.begin(), zero.end(), v) - zero.begin();
                ninv += x;
                inv += zero.size() - x;
            }
            l = r;
        }

        if( inv > ninv ){
            x += base;
            tolinv += ninv;
        }
        else{
            tolinv += inv;
        }
        base <<= 1;
    }

    cout << tolinv << " " << x << endl;
}

int main(){
    cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++){
        LL a;
        cin >> a;
        A[i] = {a, i};
    }
    solve();
}
