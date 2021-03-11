// 42m 2
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> M;

int gcd(int x, int y){
    if( y == 0 )
        return x;
    return gcd(y , x%y);
}

vector<int> l, c;

int main(){
    int n;
    cin >> n;
    
    l.resize(n);
    c.resize(n);
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++){
        if( M.find(l[i]) == M.end() )
            M[l[i]] = c[i];
        else
            M[l[i]] = min( M[l[i]], c[i] );
    }

    unordered_map<int, int> oM = M;
    unordered_set<int> Q(l.begin(), l.end());
    while( !Q.empty() ){
        unordered_set<int> Qtmp;

        for(auto &x: Q){
            for(auto yc: oM){
                int y = yc.first;
                int c = yc.second;
                int xy = gcd(x, y);
                if( M.find( xy ) == M.end() 
                        || M[xy] > M[x] + c ){
                    Qtmp.insert(xy);
                    M[xy] = M[x] + c;
                }
            }
        }

        swap( Q, Qtmp );
    }

    if( M.find(1) == M.end() )
        cout << -1 << endl;
    else
        cout << M[1] << endl;

    return 0;
}
