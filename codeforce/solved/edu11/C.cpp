// 29m
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(auto &v: A)
        cin >> v;

    int lo = n, hi = n;
    int maxF = 0, stlo = n;
    while( lo > 0 ){
        if( A[lo-1] == 0 ){
            if( k > 0 ){
                lo--;
                A[lo] = 2;
                k--;
            }
            else if( lo < hi ){
                hi--;
                if(A[hi] == 2)
                    k++;
            }
            else{
                lo--; hi--;
            }
        }
        else{
            lo--;
        }

        if( hi - lo > maxF ){
            maxF = hi - lo;
            stlo = lo;
        }
    }

    cout << maxF << endl;
    for(int i = 0; i < stlo; i++){
        if( A[i] == 1 )
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    for(int i = stlo; i < stlo + maxF; i++)
        cout << 1 << " ";
    
    for(int i = stlo+maxF; i < n ; i++){
        if( A[i] == 1 )
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}
