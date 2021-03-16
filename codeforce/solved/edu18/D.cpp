// 40m 3
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
LL n;
vector<LL> dp;

void solve(LL u, const string &pth){
    LL x = (n+1) / 2;
    while( x != u ){
        if( x < u )
            x += (x & -x) >> 1;
        else
            x -= (x & -x) >> 1;
    }
    
    for(auto &c: pth){
        if( c == 'U' && x != ((n+1) / 2)){
            if( (x & ((x&-x)<<1)) == 0 )
                x += (x&-x);
            else
                x -= (x&-x);
        }
        else if( c == 'R' && (x&1) == 0){
            x += (x & -x) >> 1;
        }
        else if( c == 'L' && (x&1) == 0){
            x -= (x & -x) >> 1;
        }
    }

    cout << x << endl;
}

/*void solve(LL u, const string &pth){
    LL root = (n+1) / 2;
    stack<LL> stk;
    stk.push(root);

    while( stk.top() != u ){
        if( u > stk.top() )
            stk.push( stk.top() + dp[stk.size()] );
        else
            stk.push( stk.top() - dp[stk.size()] );
    }

    for(auto &d: pth){
        if( d == 'U' && stk.size() > 1 ){
            stk.pop();
        }
        else if( d == 'L' && stk.size() < dp.size() ){
            stk.push( stk.top() - dp[stk.size()] );
        }
        else if( d == 'R' && stk.size() < dp.size() ){
            stk.push( stk.top() + dp[stk.size()] );
        }
    }

    cout << stk.top() << endl;
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;

    LL root = (n+1)/2;
    while( root > 0 ){
        dp.push_back(root);
        root /= 2;
    }

    LL q;
    cin >> q;
    while(q--){
        LL u;
        string pth;
        cin >> u;
        cin >> pth;
        solve(u, pth);
    }

    return 0;
}
