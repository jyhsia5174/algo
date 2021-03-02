// 30m
#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int U, int R, int D, int L){
    if( U > n || R > n || D > n || L > n )
        return false;

    int u = min(n-2,U);
    int r = min(n-2,R);
    int d = min(n-2,D);
    int l = min(n-2,L);

    for(int lu = 0; lu < 2; lu++){
        for(int ru = 0; ru < 2; ru++){
            for(int ld = 0; ld < 2; ld++){
                for(int rd = 0; rd < 2; rd++){
                    int uu = lu + ru;
                    int rr = ru + rd;
                    int dd = ld + rd;
                    int ll = lu + ld;

                    if( (uu <= U && (uu+n-2) >= U ) &&
                        (rr <= R && (rr+n-2) >= R ) &&
                        (dd <= D && (dd+n-2) >= D ) &&
                        (ll <= L && (ll+n-2) >= L ) )
                        return true;
                }
            }
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n, U, R, D, L;
    while(t--){
        cin >> n >> U >> R >> D >> L;

        if( isValid( n, U, R, D, L ) )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
