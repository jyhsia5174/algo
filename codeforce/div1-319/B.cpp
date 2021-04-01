// 2h 3
# include <bits/stdc++.h>
using namespace std;

int n;
vector<int> perm;
vector<vector<int>> cycles;

void solve(){
    int minCLen = INT_MAX;
    int minCid;
    int hasOdd = false;
    for(int i = 0; i < n; i++){
        if( perm[i] != -1 ){
            vector<int> c;
            int x = i;
            while(perm[x] != -1){
                c.push_back(x+1);
                int nx = perm[x];
                perm[x] = -1;
                x = nx;
            }

            if( c.size() % 2 == 1 ) hasOdd = true;
            if( c.size() < minCLen ){
                minCLen = c.size();
                minCid = cycles.size();
            }
            cycles.push_back(c);
        }
    }

    if( minCLen > 2 || (minCLen == 2 && hasOdd) ){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    if( minCLen == 2 )
        cout << cycles[minCid][0] << " " << cycles[minCid][1]<< endl;
    for(int i = 0; i < cycles.size(); i++){
        if(i != minCid){
            for(int j = 0; j < cycles[i].size(); j++){
                if( minCLen == 2 )
                    cout << cycles[minCid][j%2] << " " << cycles[i][j] << endl;
                else
                    cout << cycles[minCid][0] << " " << cycles[i][j] << endl;
            }
        }
    }
}


int main(){
    cin >> n;
    perm.resize(n);
    for(auto &v: perm){
        cin >> v;
        v--;
    }

    solve();
}
