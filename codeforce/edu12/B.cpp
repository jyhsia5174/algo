// 1 21m
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> item(k);
    for(auto &v: item)
        cin >> v;


    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int id;
            cin >> id;

            int l = 0;
            while( item[l] != id )
                l++;
            ans += l+1;

            while( l-1 >= 0 ){
                swap( item[l], item[l-1] );
                l--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
