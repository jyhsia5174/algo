// 12m 1
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    LL n, k;
    cin >> n >> k;

    priority_queue<LL, vector<LL>, greater<LL>> Q;
    LL rn = sqrt(n);
    for(int i = 1; i <= rn; i++){
        if( n % i == 0 ){
            Q.push(i);
            if( i != n/i )
                Q.push(n/i);
        }
    }

    if( Q.size() < k ){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < k-1; i++)
        Q.pop();
    cout << Q.top() << endl;
    return 0;
}
