// 35m 1
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

void solve(){
    int cnt = 0;
    for(int i = 0; i < n;){
        if(i+1 < n && A[i] == A[i+1] ){
            i++; continue;
        }

        if(i+1 >= n) break;
        int j = i+1;
        while(j+1 < n && A[j] != A[j+1]) j++;

        cnt = max(cnt, (j - i - 1 + 1) / 2);
        if(A[i] == A[j]){
            for(int k = i+1; k < j; k ++)
                A[k] = A[i];
        }
        else{
            for(int k = i+1; k < i + (j-i-1)/2 + 1; k++)
                A[k] = A[i];
            for(int k = i + (j-i-1)/2 + 1; k < j; k++)
                A[k] = A[j];
        }
        i = j;
    }

    cout << cnt << endl;
    for(auto &v: A)
        cout << v << " ";
    cout << endl;
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
