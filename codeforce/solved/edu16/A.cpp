// 5m 2
#include <bits/stdc++.h>
using namespace std;

vector<int> dx{0, 0, 1, -1, -1, 1, -1, 1};
vector<int> dy{1, -1, 0, 0, 1, 1, -1, -1};

int main(){
    string s;
    cin >> s;
    
    int x = s[0] - 'a';
    int y = s[1] - '1';

    int ans = 0;
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if( xx >= 0 && xx < 8 && yy >= 0 && yy < 8 )
            ans++;
    }

    cout << ans << endl;
    return 0;
}
