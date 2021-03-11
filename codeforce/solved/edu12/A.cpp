// 2 70m
#include <bits/stdc++.h>
using namespace std;

int toT( const string time ){
    // 01:34
    return stoi( time.substr(0, 2) ) * 60 + stoi(time.substr(3, 2));
}

int floor(int t, int b){
    return (t / b) * b;
}

int ceil(int t, int b){
    if( t % b == 0 )
        return t;
    return  (t / b) * b +  b;
}

int main(){
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    string time;
    cin >> time;
    int T = toT(time) - toT( "05:00" );
    int TU = toT("23:59") - toT( "05:00" );

    int lo = T - tb;
    int hi = T + ta;

    if( lo < 0 )
        lo = -b;

    lo = floor(lo, b);

    if( hi > TU )
        hi = (TU/b)*b + b;
    hi = ceil(hi, b);

    cout << (hi - lo) / b - 1 << endl;
    return 0;
}
