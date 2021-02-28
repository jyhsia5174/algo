#include <bits/stdc++.h>
using namespace std;

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
