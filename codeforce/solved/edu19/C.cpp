// 47m 3
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

void solve(){
    string S;
    cin >> S;
    dp.resize(26, 0);
    for(auto &c: S){
        c -= 'a';
        dp[c] ++;
    }

    n = S.size();

    fflush(stdout);

    int x = 0;
    stack<int> t;
    int cur_c = 0;
    while(cur_c < 26 && x < n){
        while(cur_c < 26 && dp[cur_c] == 0)
            cur_c++;

        while(!t.empty() && t.top() <= cur_c){
            cout << (char) ('a' + t.top());
            t.pop();
        }

        if( S[x] == cur_c )
            cout << (char) ('a' + S[x]);
        else
            t.push(S[x]);
        dp[S[x]]--;
        x++;
    }

    while(!t.empty()){
        cout << (char) ('a' + t.top());
        t.pop();
    }
    cout << endl;
}

int main(){
    solve();
}
