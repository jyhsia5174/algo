#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int n;
vector<bool> u;
vector<int> cnt;
vector<int> A;

int inc(int x){
    return (x+1) % n;
}

int gcd(int x, int y){
    if( y == 0 )
        return x;
    return gcd(y, x % y);
}

void solve(){
    LL res = 0;
    u.resize(n);
    cnt.resize(n+1);
    vector<int> gg(n+1);
    for(int i = 1; i <= n; i++)
        gg[i] = gcd(n, i);
    
    for(int g = 1; g < n; g++){
        if( n % g != 0 ) continue;
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < g; i++){
            int mx = -1;
            for(int j = i; j < n; j += g) mx = max(mx, A[j]);
            for(int j = i; j < n; j += g) u[j] = (A[j] == mx);
        }

        bool any = false;
        for(int l = 0; l < n;){
            int r = inc(l);
            if(u[l]){
                l++;
                continue;
            }
            any = true;
            int len = 0;
            while(u[r]) len++, r = inc(r);
            for(int i = 1; i <= len; i++) 
                cnt[i] += len - i + 1;
            if(r <= l) break;
            l = r;
        }

        if(!any){
            for(int i = 1; i <= n; i++)
                cnt[i] += n;
        }

        for(int i = 1; i <= n; i++)
            if(gg[i] == g)
                res += cnt[i];
    }

    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    A.resize(n);
    for(auto &v: A)
        cin >> v;
    solve();
    return 0;
}
