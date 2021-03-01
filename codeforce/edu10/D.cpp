#include <bits/stdc++.h>
using namespace std;

class FT{
public:
    FT(int _n){
        n = _n;
        tree.resize(n+1, 0);
    }

    void add(int x, int val){
        while(x <= n){
            tree[x] += val;
            x += ( x & -x );
        }
    }

    int sum(int x){
        int res = 0;
        x = min(n, x);
        while( x > 0 ){
            res += tree[x];
            x -= ( x & -x );
        }
        return res;
    }

    vector<int> tree;
    int n;
};

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> A;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        A.push_back( {l, 2*i} );
        A.push_back( {r, 2*i+1} );
    }

    sort(A.begin(), A.end());
    int rk = 1;
    FT tree(n);
    vector<int> open(n+1, -1);
    vector<int> ans(n+1);
    for(int i = 0; i < A.size(); i++){
        auto &v = A[i];
        int id = v[1] / 2;
        bool isRight = (v[1] % 2 == 1);

        if(isRight){
            ans[id] = tree.sum(rk) - tree.sum(open[id]);
            tree.add(open[id] , 1);
        }
        else{
            open[id] = rk;
            rk++;
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;

    return 0;
}
