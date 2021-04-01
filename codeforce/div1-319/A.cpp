// 24m 1
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> prime;

void init(){
    vector<int> used(n+1, false);
    for(int i = 2; i <= n; i++){
        if(used[i] == false){
            prime.push_back(i);
            int x = i;
            while(x <= n){
                used[x] = true;
                x += i;
            }
        }
    }
}

void solve(){
    vector<int> Q;
    for(auto &p: prime){
        int x = p;
        while(x <= n){
            Q.push_back(x);
            x *= p;
        }
    }

    cout << Q.size() << endl;
    for(auto &v: Q)
        cout << v << " ";
    cout << endl;
}

int main(){
    cin >> n;
    init();
    solve();
}
