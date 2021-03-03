#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> dp(m+1, 0);
    for(auto &a: A){
        cin >> a;
        if( a <= m )
            dp[a]++;
    }

    vector<int> divCnt(m+1, 0);
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= m; j+=i)
            divCnt[j] += dp[i];
    }

    int lcm = 1;
    for(int i = 2; i <= m; i++)
        if( divCnt[i] > divCnt[lcm] )
            lcm = i;

    cout << lcm << " " << divCnt[lcm] << endl;
    for(int i = 0; i < n; i++){
        if( lcm % A[i] == 0 )
            cout << i+1 << " ";
    }
    cout << endl;
    
    return 0;
}

/*
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> A;
    unordered_map<int, int> M;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
        M[tmp]++;
    }

    vector<int> dp(m+1, 0);
    for(int i = m; i >= 1; i--){
        if( M.find(i) != M.end() ){
            int j = i;
            while(j <= m){
                dp[j] += M[i];
                j += i;
            }
        }
    }

    int l = 0, k = 1;
    for(int i = 1; i <= m; i++){
        if( dp[i] > l ){
            l = dp[i];
            k = i;
        }
    }

    cout << k << " " << l << endl;
    for(int i = 0; i < n; i++){
        if( k % A[i] == 0 )
            cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}
*/
