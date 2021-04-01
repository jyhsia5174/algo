// 2 120
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef vector<vector<LL>> mt;
const LL INF = LLONG_MAX / 2;
LL n, t;

void printM(const mt &M){
    cout << "[" << endl;
    for(auto &v: M){
        for(auto &mij: v){
            if( mij < 0 )
                cout << "-" << "\t";
            else
                cout << mij << "\t";
        }
        cout << endl;
    }
    cout << "]" << endl;
}


void init(mt &M){
    M.resize(n, vector<LL>(n, 0));
}

void fill(mt &M, LL val){
    for(int i = 0; i < n; i++)
        fill(M[i].begin(), M[i].end(), val);
}

void op(const mt &M1, const mt &M2, mt &M3){
    fill(M3, -INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if( M1[i][k] != -INF || M3[k][j] != -INF )
                    M3[i][j] = max(M3[i][j], M1[i][k] + M2[k][j]);
            }
        }
    }
}

void Mpow(mt &M1, LL t, mt &M2){
    fill(M2, 0);
    mt tmp;
    init(tmp);
    while(t > 0){
        if(t&1){
            op(M1, M2, tmp);
            swap(M2, tmp);
        }
        op(M1, M1, tmp);
        swap(M1, tmp);
        t >>= 1;
    }
}

void solve(){
    vector<LL> A(n);
    for(auto &v: A)
        cin >> v;

    mt M1, M2;
    init(M1);
    fill(M1, -INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( A[j] >= A[i] ){
                M1[i][j] = 1;
                for(int k = 0; k < j; k++){
                    if(A[k] <= A[j])
                        M1[i][j] = max(M1[i][j], M1[i][k] + 1);
                }
            }
        }
    }


    init(M2);
    Mpow(M1, t, M2);
    
    LL res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res = max( res, M2[i][j] );
    cout << res << endl;
}


int main(){
    cin >> n >> t;
    solve();
}
