// 15m 1
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    int n, k;
    string s;
    while(t--){
        cin >> n >> k;
        cin >> s;

        int cnt = 0;
        for(int i = 0; i < (n+1)/2 - 1; i++){
            if( s[i] == s[n-1-i] )
                cnt++;
            else
                break;
        }

        if( cnt >= k )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
