// 20 57m
/*
.d
d.
d.d
d
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    size_t x = s.find_first_of("123456789");
    size_t y = s.find_last_of("123456789");
    size_t z = s.find('.');
    if( z == string::npos ){
        s += ".";
        z = s.size() - 1;
    }

    if( x == string::npos ){
        cout << 0 << endl;
    }
    else{
        int pow = (z < x)? z - x : z - (x + 1);

        string ss;
        for(int i = x; i <= y; i++)
            if(s[i] != '.')
                ss.push_back(s[i]);

        cout << ss[0];
        if(ss.size() > 1)
            cout << "." + ss.substr(1, ss.size()-1);
        if(pow != 0)
            cout << "E" << pow;
    }

    return 0;
}
