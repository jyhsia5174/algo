// 2 12m
#include <bits/stdc++.h>
using namespace std;

bool isleap(int y){
    if( y % 400 == 0 )
        return true;
    if( y % 4 == 0 && y % 100 != 0 )
        return true;

    return false;
}

int nday(int y){
    return (isleap(y))? 366 : 365;
}

int main(){
    int y;
    cin >> y;

    int yleap = isleap(y);
    int sum = nday(y);
    y++;
    int m = 7;
    while( sum % m != 0 || yleap != isleap(y) ){
        sum = sum + nday(y);
        y++;
    }

    cout << y << endl;
    return 0;
}
