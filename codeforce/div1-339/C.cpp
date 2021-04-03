#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

void solve(){
    int oddcnt = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if( A[i] % 2 == 1 ) oddcnt++;
        sum += A[i];
    }

    string res = "";
    if( oddcnt >= 2 ){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < A[i]; j++)
                res.push_back('a'+i);
        }
        cout << 0 << endl << res << endl;
        return;
    }

    int part = sum;
    for(int i = 0; i < n; i++){
        if(A[i] == 0) continue;
        part = gcd(part, A[i]);
    }

    string partS = "";
    string partSrev = "";
    if(oddcnt == 0){
        for(int i = 0; i < n; i++){
            if( A[i] == 0 ) continue;
            for(int j = 0; j < A[i]/part; j++){
                partS.push_back('a'+i);
            }
        }
        partSrev = partS;
        reverse(partSrev.begin(), partSrev.end());
    }
    else{
        string S1, S2;
        for(int i = 0; i < n; i++){
            if( A[i] == 0 ) continue;
            if( A[i] % 2 == 1 ){
                for(int j = 0; j < A[i]/part; j++){
                    S2.push_back('a'+i);
                }
            }
            else{
                for(int j = 0; j < A[i]/part/2; j++){
                    S1.push_back('a'+i);
                }
            }
        }
        partS = S1 + S2;
        reverse(S1.begin(), S1.end());
        partS += S1;
    }

    for(int i = 0; i < part; i++){
        if(oddcnt == 0 && i % 2 == 0){
            res += partSrev; // bug1: forget to reverse
        }
        else{
            res += partS;
        }
    }
    cout << part << endl << res << endl;
}

int main(){
    cin >> n;
    A.resize(n);
    for(auto &v: A)
        cin >> v;
    solve();
}
