// 17m 2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for(auto &v: A)
        cin >> v;

    int cnt = n;
    int leader = 0;
    vector<bool> player(n, true);
    for(auto &v: A){
        int x = v % cnt;
        int y = leader;
        while(x > 0){
            y = (y + 1) % n;
            if(player[y])
                x--;
        }
        player[y] = false;
        cnt--;
        cout << y+1 << endl;
        while( !player[y] ) y = (y+1) % n;
        leader = y;
    }

    return 0;
}
