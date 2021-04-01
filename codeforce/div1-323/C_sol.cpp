#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 5;
int a[N], n, c[N], gg[N];
bool u[N];

inline int inc(int v) { return (v + 1 == n) ? 0 : (v + 1); }
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    assert(scanf("%d", &n) == 1);
    for (int i = 0; i < n; ++i) assert(scanf("%d", &a[i]) == 1);
    for (int i = 1; i <= n; ++i) gg[i] = gcd(i, n);
    long long res = 0;
    for (int g = 1; g < n; ++g) {
        if (n % g != 0) continue;
        for (int i = 0; i < n; ++i) u[i] = false, c[i] = 0;
        for (int i = 0; i < g; ++i) {
            int mx = -1;
            for (int j = i; j < n; j += g) mx = max(mx, a[j]);
            for (int j = i; j < n; j += g) 
                if (a[j] == mx) u[j] = true;
        }
        bool any = false;
        for (int l = 0; l < n;) {
            int r = inc(l);
            if (u[l]) { l++; continue; }
            any = true;
            int len = 0;
            while (u[r]) len++, r = inc(r);
            for (int i = 1; i <= len; ++i) c[i] += len - i + 1;
            if (r <= l) break;
            l = r;
        }
        if (!any)
            for (int i = 1; i <= n; ++i) c[i] += n;
        for (int i = 1; i <= n; ++i)
            if (gg[i] == g) res += c[i];
    }
    cout << res << endl;
    return 0;
}
