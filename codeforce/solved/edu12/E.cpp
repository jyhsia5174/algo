#include <bits/stdc++.h>
using namespace std;

int nex[30000000][2], co[30000000], ne = 0;
long long ans = 0;

void ins(int num){
    int cur = 0;
    for(int i = 0; i < 30; i++){
        int temp = (num>>i) & 1;
        if( !nex[cur][temp] )
            nex[cur][temp] = ++ne;
        cur = nex[cur][temp];
        co[cur]++;
    }
}

int query(int ind, int num, int low, int cur){
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto &a: A)
        cin >> a;

    vector<int> dp(n+1, 0);
    for(int i = 1; i <= A; i++){
        dp[i] = dp[i] ^ A[i-1];
    }
}
