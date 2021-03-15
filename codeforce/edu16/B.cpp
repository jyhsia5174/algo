// 7m 1
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> pos(n);
    for(auto &v: pos)
        cin >> v;

    sort(pos.begin(), pos.end());
    cout << pos[(n-1)/2] << endl;

    return 0;
}
