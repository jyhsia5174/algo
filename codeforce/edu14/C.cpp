// 20 57m
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    size_t x = s.find_first_of("123456789");
    size_t y = s.find_last_of("123456789");
    size_t z = s.find('.');

    if( x == string::npos ){
        cout << 0 << endl;
    }
    else{
        if( z == string::npos ){
            if( x == y ){
                cout << s[x];
            }
            else{
                cout << s[x];
                cout << "." + s.substr(x+1, y-x);
            }

            if( s.size() - x - 1 > 0 )
                cout << "E" << s.size() - x - 1;
        }
        else{
            int pow;
            if( z < x )
                pow = z - x;
            else
                pow = z - (x+1);

            string ss;
            for(int i = x; i <= y; i++)
                if( s[i] != '.' )
                    ss.push_back(s[i]);

            if(ss.size() == 1){
                cout << ss;
                if( pow != 0 )
                    cout << "E" << pow;
            }
            else{
                cout << ss[0];
                cout << "." + ss.substr(1, ss.size()-1);
                if(pow != 0)
                    cout << "E" << pow;
            }
        }
    }

    return 0;
}
