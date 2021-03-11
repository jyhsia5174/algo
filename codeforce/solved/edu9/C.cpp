#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> s(n);
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        s[i] = tmp;
    }

    sort( s.begin(), s.end(), [](const string &l, const string &r){
        return l + r < r + l;
    } );

    string ans = "";
    for(auto &w: s)
        ans += w;

    cout << ans << endl;
    return 0;
}
