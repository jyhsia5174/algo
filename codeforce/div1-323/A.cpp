// 20m 2
#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> M;

void take(int x){
    M[x]--;
    if( M[x] == 0 )
        M.erase(x);
}

int gcd(int x, int y){
    if( y == 0 )
        return x;
    return gcd( y, x % y );
}

int main(){
    cin >> n;
    int nn = n*n;
    for(int i = 0; i < nn; i++){
        int a;
        cin >> a;
        M[a]++;
    }

    vector<int> sol;
    for(int i = 0; i < n; i++){
        int x = M.rbegin()->first;
        take(x);
        for(auto &y: sol){
            int gcdxy = gcd(x, y);
            take(gcdxy);
            take(gcdxy);
        }
        sol.push_back(x);
    }

    for(auto &v: sol)
        cout << v << " ";
    cout << endl;
}
