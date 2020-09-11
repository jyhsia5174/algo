// Partition problem | DP-18
// https://www.geeksforgeeks.org/partition-problem-dp-18/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<int> A(N);
    int total = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        total += A[i];
    }
    
    if( total % 2 == 1 ){
        cout << "NO" << endl;
        return;
    }
    
    int target = total / 2;
    
    vector<vector<int>> dp(N+1, vector<int>(target+1, 0) );
    for(int i = 0; i < N+1; i++)
        dp[i][0] = 1;

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < target+1; j++){
            dp[i][j] = dp[i-1][j];
            if( (j - A[i-1]) >= 0 && dp[i-1][j - A[i-1]] == 1 ){
                dp[i][j] = 1;
            }
        }
        if( dp[i][target] == 1 ){
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main() {
	//code
	int T;
	cin >> T;
	while( T > 0 ){
	    solve();
	    T--;
	}
	return 0;
}
