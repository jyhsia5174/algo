// 30m 2
#include <bits/stdc++.h>
using namespace std;

int count(const vector<int> &perm){
    int res = 0;
    for(int i = 0; i < perm.size(); i++){
        for(int j = i+1; j < perm.size(); j++){
            if( perm[i] > perm[j] )
                res++;
        }
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> perm(n);
    for(auto &v: perm)
        cin >> v;

    map<vector<int>, int> Q;
    Q[perm] = 1;

    for(int i = 0; i < k; i++){
        map<vector<int>, int> Qtmp;
        for(auto &kv: Q){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j <= n; j++){
                    vector<int> p = kv.first;
                    reverse(p.begin()+i, p.begin()+j);
                    Qtmp[p] += kv.second;
                }
            }
        }
        swap(Q, Qtmp);
    }

    double inv = 0;
    double sum = 0;
    for(auto &kv: Q){
        inv += count(kv.first) * kv.second;
        sum += kv.second;
    }
    
    cout << setprecision(20) << inv / sum << endl;
    return 0;
}
