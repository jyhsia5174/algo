#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sol;
vector<int> getres;
int cnt;

void query(const vector<int>& Q){
    cout << Q.size() << endl;
    for(auto &v: Q)
        cout << v << " ";
    cout << endl;
    fflush(stdout);

    // get result
    for(int i = 1; i <= n; i++)
        cin >> getres[i];
}

void update(const vector<int> &A, const vector<int> &offset, int sz){
    vector<int> Q;
    for(auto &ai: A){
        for(auto &i: offset)
            if(ai+i<=n)
                Q.push_back(ai + i);
    }
    query(Q);

    for(auto &ai: A){
        for(int i = (offset.back()+1)%sz; i != offset[0]; i = (i+1)%sz){
            int x = ai + i;
            if( x <= n ){
                sol[x] = min( sol[x], getres[x]);
            }
        }
    }
    fflush(stdout);
}

void solve(vector<int> &A, int sz){
    if( sz <= 1 ) return;
    if( sz % 2 == 1 ){
        vector<int> m{sz/2};
        update(A, m, sz);
    }
    vector<int> l(sz/2), r(sz/2);
    iota(l.begin(), l.end(), 0);
    iota(r.begin(), r.end(), (sz+1)/2);
    update(A, l, sz);
    update(A, r, sz);

    int Asz = A.size();
    for(int i = 0; i < Asz; i++)
        A.push_back( A[i] + (sz+1) / 2 );
    solve(A, sz/2);
}

int main(){
    cnt = 0;
    //ios_base::sync_with_stdio(false);
    cin >> n;

    getres.resize(n+1, INT_MAX);
    sol.resize(n+1, INT_MAX);
    
    int aln = 1;
    while( aln < n )
        aln *= 2;
    vector<int> A{1};
    solve(A, aln);
   

    cout << -1 << endl;
    for(int i = 1; i <= n; i++)
        cout << sol[i] << " ";
    cout << endl;
    fflush(stdout);

    return 0;
}
