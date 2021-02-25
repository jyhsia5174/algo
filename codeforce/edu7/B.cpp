// 8m
#include <bits/stdc++.h>
using namespace std;

class solver{
    public:
        string wait(int hh, int mm, int a){
            a = a % (24 * 60);

            while(a > 0){
                mm++;
                if( mm == 60 ){
                    hh = (hh+1) % 24;
                    mm = 0;
                }
                a--;
            }

            string res = "";
            if( hh / 10 == 0 )
                res += "0";
            res += to_string( hh );
            res += ":";

            if( mm / 10 == 0 )
                res += "0";
            res += to_string( mm );
            return res;
        }
};

int main(){
    char dummy;
    int hh, mm;
    cin >> hh >> dummy >> mm;
    int a;
    cin >> a;

    solver mySol;
    cout << mySol.wait(hh, mm, a) << endl;
}
