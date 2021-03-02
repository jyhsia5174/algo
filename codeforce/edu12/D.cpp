/*


1   1   x

1   x   x

1   e   e   (no
1   e   o   (no
1   o   o   (no

x   x   x

e   e   e   (no
e   o   o   (no
o   o   o   (no

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &v: A)
        cin >> v;

    vector<bool> prime(2e6+1, true);
    prime[1] = false;
    for(int i = 2; i <= 2e6; i++){
        if( prime[i] ){
            int j = i+i;
            while( j <= 2e6 ){
                prime[j] = false;
                j += i;
            }
        }
    }

    int len = 1;
    vector<int> res{A[0]};
    vector<int> one;
    int X = -1;
    for(int i = 0; i < n; i++){
        if( A[i] == 1 )
            one.push_back(A[i]);
        
        if( A[i] != 1 && X == -1 && prime[A[i]+1] )
            X = A[i];
        

        if( len < 2 ){
            for(int j = i+1; j < n; j++){
                if( prime[A[i]+A[j]] ){
                    len = 2;
                    res = {A[i], A[j]};
                    break;
                }
            }
        }
    }

    if( one.size() > 0 && X != -1 )
        one.push_back(X);

    if( one.size() > len ){
        len = one.size();
        res = one;
    }

    cout << len << endl;
    for(auto &v: res)
        cout << v << " ";
    cout << endl;

    return 0;
}
