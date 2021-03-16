// 10m 1
#include <bits/stdc++.h>
using namespace std;

bool equal(string &a, string &b){
    int n = a.size();
    if( n % 2 == 0 ){
        string a1 = a.substr(0, n/2);
        string a2 = a.substr(n/2, n/2);
        string b1 = b.substr(0, n/2);
        string b2 = b.substr(n/2, n/2);
        return (a == b)
            || ( equal(a1, b1) && equal(a2, b2) ) 
            || ( equal(a2, b1) && equal(a1, b2));
    }

    return a == b;
}

int main(){
    string a, b;
    cin >> a >> b;
    
    if( equal(a, b) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
