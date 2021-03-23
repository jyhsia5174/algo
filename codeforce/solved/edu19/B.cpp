// 15m 2
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

void solve(){
    LL n;
    cin >> n;
    vector<LL> A(n);
    for(auto &a: A)
        cin >> a;

    LL evenPosSum = 0;
    vector<LL> odd;
    for(auto &a: A){
        if( a % 2 == 0 && a > 0 )
            evenPosSum += a;
        else if( abs(a % 2) == 1 )
            odd.push_back(a);
    }

    sort(odd.begin(), odd.end(), greater<LL>());
    LL oddPosSum = 0;
    LL x = 0;
    for(auto &a: odd){
        if( a < 0 )
            break;
        oddPosSum += a;
        x++;
    }

    if( x % 2 == 1 ){
        cout << evenPosSum + oddPosSum << endl;
    }
    else{
        if( x == 0 ){
            cout << evenPosSum + odd[x] << endl;
        }
        else if( x < odd.size() ){
            oddPosSum = max( oddPosSum - odd[x-1], oddPosSum + odd[x] );
            cout << evenPosSum + oddPosSum << endl;
        }
        else{
            cout << evenPosSum + oddPosSum - odd[x-1] << endl;
        }
    }
}

int main(){
    solve();
}
