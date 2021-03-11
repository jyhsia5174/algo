/*
17m
2th: 3   7   8   4
1st: 1   5   6   2           
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n+1, {-1, -1, -1, -1, -1});

    for(int i = 1; i <= m; i++){
        if( i <= 2*n ){
            int x = (i+1) / 2;
            if( i % 2 == 0 ){
                A[x][4] = i;
            }
            else{
                A[x][1] = i;
            }
        }
        else{
            int x = (i-2*n+1) / 2;
            if( i % 2 == 0 ){
                A[x][3] = i;
            }
            else{
                A[x][2] = i;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if( A[i][2] != -1 )
            cout << A[i][2] << " ";
        if( A[i][1] != -1 )
            cout << A[i][1] << " ";
        if( A[i][3] != -1 )
            cout << A[i][3] << " ";
        if( A[i][4] != -1 )
            cout << A[i][4] << " ";
    }

    return 0;
}
