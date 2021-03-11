#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, b, p;

    cin >> n >> b >> p;
   
    int towel = n*p;
    int bottle = 0;
    while( n > 1 ){
        int k = 1;
        while( (k << 1) <= n )
            k <<= 1;

        bottle += b * k + k / 2;
        n =  (n-k) + k / 2;
    }

    cout << bottle << " " << towel << endl;

    return 0;
}
