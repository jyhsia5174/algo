// 2 5m
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int zeroCnt = 0;
    int val;
    int i = n;
    while(i){
        cin >> val;
        if( val == 0 )
            zeroCnt++;
        i--;
    }

    if( n == 1 ){
        if( zeroCnt == 0 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else{
        if( zeroCnt == 1 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
