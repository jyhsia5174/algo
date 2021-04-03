#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n, A, cf, cm, m;
vector<vector<LL>> sk;
vector<LL> need;

int main(){
    cin >> n >> A >> cf >> cm >> m;
    sk.resize(n+1);
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        sk[i] = {a, i};
    }
    sort(sk.begin()+1, sk.end());
    sk.push_back({(int)A, n+1});
    
    need.resize(n+1, 0);
    for(int i = 2; i <= n; i++)
        need[i] = need[i-1] + (i-1) * (sk[i][0] - sk[i-1][0]);

    LL taken = 0, besi, beso, bess = -1; // bug6: bess should be -1 not zero
    for(int i = 0; i <= n; i++){
        taken += A - sk[n+1-i][0]; // bug4: sk[n+1-i][0] not sk[..][1]
        LL rem = m - taken;
        if(rem < 0)
            break;

        LL p = 0;
        for(int j = n+1-i-p; j >= 1; j /= 2){
            while(p+j < n+1-i && need[p+j] <= rem ) p += j;
        }

        LL o = 0; // bug5: int overflow
        if(p == 0)
            o = A;
        else
            o = min(A, sk[p][0] + (rem-need[p])/p); // bug3: sk[p][0] not need[p]

        LL s = i*cf + o*cm;
        if(s > bess){
            bess = s;
            besi = i;
            beso = o;
        }
    }

    vector<LL> ans(n+1);
    for(int i = n; i > n-besi; i--)
        ans[sk[i][1]] = A;
    for(int i = 1; i <= n-besi; i++){ // bug4: i <= n-besi not i <= n
        if(sk[i][0] >= beso)
            ans[sk[i][1]] = sk[i][0];
        else
            ans[sk[i][1]] = beso;
    }

    cout << bess << endl;
    for(int i = 1; i <= n; i++) // bug1: 1 to n
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
