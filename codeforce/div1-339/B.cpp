// 10 2h
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n, amax, c1, c2, m;
vector<LL> A;
vector<LL> idx;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> amax >> c1 >> c2 >> m;
    A.resize(n);
    idx.resize(n);
    for(auto &v: A)
        cin >> v;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](LL l, LL r){
            return A[l] < A[r];
            });

    int p2 = n-1;
    vector<LL> use(n, 0);
    while(p2 >= 0){
        if(A[idx[p2]] + m < amax) break;
        m -= amax - A[idx[p2]];
        p2--;
    }

    LL score = -1;
    int p3 = p2;
    int p4 = 0;
    LL bmaxmin = A[idx[0]];
    int p1 = 0;
    LL sum = A[idx[p1]];
    while(p2 <= n-1){
        while(p1 < p2 && (A[idx[p1+1]]*(p1+1) - sum) <= m){
            p1++;
            sum += A[idx[p1]];
        }

        LL maxmin = amax;
        if(p1 <= p2){
            maxmin = A[idx[p1]] 
                + (m - (A[idx[p1]]*(p1+1) - sum)) / (p1+1);
            maxmin = min(amax, maxmin);
        }

        LL nscore = (n-p2-1)*c1 + maxmin * c2;
        if(nscore > score){
            score = nscore;
            p3 = p2;
            p4 = p1;
            bmaxmin = maxmin;
        }

        p2++;
        if(p2 < n) m += amax - A[idx[p2]];
    }
    
    for(int i = n-1; i > p3; i--){
        A[idx[i]] = amax;
    }

    for(int i = 0; i <= p4; i++){
        A[idx[i]] = bmaxmin;
    }

    cout << score << endl;
    for(auto &a: A)
        cout << a << " ";
    cout << endl;
    return 0;
}

