// 19m 2
// parse input error not cin >> int 
#include <bits/stdc++.h>
using namespace std;

int n;
class uf{
    public:
        vector<int> p;
        uf(){
            p.resize(301);
            iota(p.begin(), p.end() , 0);
        }

        int find(int x){
            if(x == p[x])
                return x;
            p[x] = find( p[x] );
            return p[x];
        }

        void merge(int x, int y){
            x = find(x);
            y = find(y);
            if( x == y )
                return;
            p[x] = y;
        }
};

void solve(){
    cin >> n;
    vector<int> perm(n);
    for(auto &v: perm)
        cin >> v;

    uf u;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char aij;
            cin >> aij;
            if( aij == '1' )
                u.merge(i, j);
        }
    }

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> M;
    for(int i = 0; i < n; i++){
        int ri = u.find(i);
        M[ri].push(perm[i]);
    }

    for(int i = 0; i < n; i++){
        int ri = u.find(i);
        cout << M[ri].top() << " ";
        M[ri].pop();
    }
    cout << endl;
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
