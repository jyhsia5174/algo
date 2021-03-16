// 15m 2
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    //ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    priority_queue<int, vector<int>, greater<int>> usb, ps;
    for(int i = 0; i < m; i++){
        int price;
        string tag;
        cin >> price >> tag;
        if( tag == "USB" ){
            usb.push(price);
        }
        else{
            ps.push(price);
        }
    }

    int cnt = 0;
    LL amt = 0;
    while( a > 0 && !usb.empty() ){
        cnt++;
        amt += usb.top();
        usb.pop();
        a--;
    }

    while( b > 0 && !ps.empty() ){
        cnt++;
        amt += ps.top();
        ps.pop();
        b--;
    }

    while( c > 0 && ( !usb.empty() && !ps.empty() ) ){
        cnt++;
        if( usb.top() < ps.top() ){
            amt += usb.top();
            usb.pop();
        }
        else{
            amt += ps.top();
            ps.pop();
        }
        c--;
    }

    while( c > 0 && !usb.empty() ){
        cnt++;
        amt += usb.top();
        usb.pop();
        c--;
    }

    while( c > 0 && !ps.empty() ){
        cnt++;
        amt += ps.top();
        ps.pop();
        c--;
    }

    cout << cnt << " " << amt << endl;
    return 0;
}
