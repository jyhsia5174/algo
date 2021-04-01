#include <bits/stdc++.h>
using namespace std;

typedef long long li;
const int N = 100 + 5;
const li INF = li(1e15);
typedef li mt[N][N];

int n, a[N];
li T;
mt d, dt;
                        
void one(mt a) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = 0;
}

void copy(const mt a, mt b) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = a[i][j];
}

void mul(const mt a, const mt b, mt c) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            c[i][j] = -INF;
            for (int k = 0; k < n; ++k)
                c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
        }
}

mt t, r;
void binpow(const mt a, li b, mt c) {
    copy(a, t);
    one(c);
    while (b) {
        if (b & 1) {
            mul(c, t, r);
            copy(r, c);
        }
        mul(t, t, r);
        copy(r, t);
        b >>= 1;
    }
}

int main() {
    cin >> n >> T;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int s = 0; s < n; ++s) {
        for (int i = 0; i < n; ++i) {
            if (a[i] < a[s]) {
                d[s][i] = -INF;
            } else {
                d[s][i] = 1;
                for (int j = 0; j < i; ++j)
                    if (a[j] <= a[i])
                        d[s][i] = max(d[s][i], d[s][j] + 1);
            }
        }
    }
    binpow(d, T, dt);
    li res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res = max(res, dt[i][j]);
    cout << res << endl;
    return 0;
}
