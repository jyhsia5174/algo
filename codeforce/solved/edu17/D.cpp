// 90m 1
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    int n;
    cin >> n;

    vector<vector<LL>> A(n, vector<LL>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> A[j][i];

    vector<LL> pre(3), cur(3);
    pre[0] = A[0][0];
    pre[1] = pre[0] + A[0][1];
    pre[2] = pre[1] + A[0][2];

    LL sum = pre[2];
    for(int i = 1; i < n; i++){
        // update 0
        cur[0] = pre[0];
        cur[0] = max( cur[0], pre[1] + A[i][1] );
        cur[0] = max( cur[0], pre[2] + A[i][2] + A[i][1] );
        cur[0] += A[i][0];

        // update 1
        cur[1] = pre[0] + A[i][0];
        cur[1] = max( cur[1], pre[1] );
        cur[1] = max( cur[1], pre[2] + A[i][2] );
        cur[1] += A[i][1];
        
        // update 2
        cur[2] = pre[0] + A[i][0] + A[i][1];
        cur[2] = max( cur[2], pre[1] + A[i][1] );
        cur[2] = max( cur[2], pre[2] );
        cur[2] += A[i][2];

        LL sumi = 0;
        for(int j = 0; j < 3; j++)
            sumi += A[i][j];
        cur[0] = max(cur[0], sum + sumi);
        cur[2] = max(cur[2], sum + sumi);
        if( max(pre[0], pre[2]) > sum )
            sum = sumi + max(pre[0], pre[2]);
        else
            sum += sumi;
        swap(pre, cur);
    }

    cout << pre[2] << endl;
    return 0;
}
