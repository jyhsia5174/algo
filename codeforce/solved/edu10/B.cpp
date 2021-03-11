// 15m
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &a: A)
        cin >> a;

    sort(A.begin(), A.end(), greater<int>());
    int ai = 0;
    vector<int> ans(n);
    for(int i = 1; i < n; i+=2, ai++)
        ans[i] = A[ai];

    bool possible = true;
    for(int i = 0; i < n; i+=2, ai++){
        ans[i] = A[ai];
        if( i-1 >= 0 && ans[i] > ans[i-1] ){
            possible = false;
            break;
        }

        if( i+1 < n && ans[i] > ans[i+1] ){
            possible = false;
            break;
        }
    }

    if( possible ){
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    else
        cout << "Impossible" << endl;

    return 0;
}
