// 17m
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int h1, h2;
    int a, b;

    cin >> h1 >> h2 >> a >> b;

    h1 += a * 8;
    if( h1 >= h2 )
        cout << 0 << endl;
    else if( a - b <= 0 )
        cout << -1 << endl;
    else{
        int speed = (a - b) * 12;
        if( (h2 - h1) % speed == 0 )
            cout << (h2 - h1) / speed << endl;
        else
            cout << (h2 - h1) / speed + 1 << endl;
    }

    return 0;
}
