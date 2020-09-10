// Palindrome Partitioning | DP-17
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INF 1e7

void solve(){
    string s;
    cin >> s;
    
    const int N = s.size();
    vector<int> dp(N+1);
    iota(dp.begin(), dp.end(), -1);
    queue<int> Q, Qtmp;
    Q.push(0);
    for(int i = 0; i < N; i++){
        while( !Q.empty() ){
            int len = Q.front();
            Q.pop();
            int l = i - len - 1;
            if( l >= 0 && s[l] == s[i] ){
                dp[i+1] = min( dp[i+1], dp[l] + 1 );
                Qtmp.push( i - l + 1 );
            }
        }
        dp[i+1] = min( dp[i+1], dp[i] + 1 );
        Qtmp.push(1);
        Qtmp.push(0);
        swap( Q, Qtmp );
    }
    
    cout << dp[N] << endl;
}

int main() {
	//code
	int T, t = 0;
	cin >> T;
	while(t < T){
	    solve();
	    t++;
	}
	return 0;
}
