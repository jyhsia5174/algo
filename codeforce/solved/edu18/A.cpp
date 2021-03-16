// 8m 1
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cood(n);

    for(auto &v: cood)
        cin >> v;

    sort(cood.begin(), cood.end());

    int mindist = INT_MAX;
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        int dist = cood[i+1] - cood[i];
        if( dist < mindist ){
            mindist = dist;
            cnt = 0;
        }

        if( dist == mindist )
            cnt++;
    }

    cout << mindist << " " << cnt << endl;
    return 0;
}
