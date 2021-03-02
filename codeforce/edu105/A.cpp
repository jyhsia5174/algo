// 18m
#include <bits/stdc++.h>
using namespace std;

bool isValid(string &ABC){
    const int n = ABC.size();
    int type[3];

    for(int i = -1; i <= 1; i+= 2){
        type[0] = i;
        for(int j = -1; j <= 1; j+= 2){
            type[1] = j;
            for(int k = -1; k <= 1; k+= 2){
                type[2] = k;
                int count = 0;
                for(int l = 0; l < n; l++){
                    int c = ABC[l] - 'A';
                    count += type[c];
                    if( count < 0 )
                        break;
                }
                if( count == 0 )
                    return true;
            }
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t){
        string ABC;
        cin >> ABC;
        if( isValid( ABC ) ){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        t--;
    }
    
    return 0;
}
