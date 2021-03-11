// 120 3 
#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int acidi = 0;
unordered_map<int, unordered_map<int, int>> acid;
vector<vector<int>> E;

void insert_acid(int a, int c){
    if( acid[a].find(c) == acid[a].end() ){
        acid[a][c] = acidi;
        acidi++;
    }
}

class uf{
public:
    vector<int> p;
    uf(){
        p.resize(2e5+5);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        if( x == p[x] )
            return x;
        p[x] = find( p[x] );
        return p[x];
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);

        if( x == y ) return;
        p[x] = y;
    }
};

uf u;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    /*for(int i = 0; i < n; i++)
        acid[i] = {};*/

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        insert_acid(a, c);
        insert_acid(b, c);
        u.merge(acid[a][c], acid[b][c]);
    }

    cin >> q;
    map<vector<int>, int> memo;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if( acid[a].size() > acid[b].size() 
                || (acid[a].size() == acid[b].size() && a > b) ) swap(a, b);

        if( memo.find( {a, b} ) == memo.end() ){
            int ans = 0;
            for(auto cid: acid[a]){
                int c = cid.first;
                int A = cid.second;
                if(acid[b].find(c) != acid[b].end()){
                    int B = acid[b][c];
                    if( u.find(A) == u.find(B) )
                        ans++;
                }
            }
            memo[{a,b}] = ans;
        }

        cout << memo[{a,b}] << endl;
    }

    return 0;
}
