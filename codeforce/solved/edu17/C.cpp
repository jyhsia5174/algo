// 1h 5
#include <bits/stdc++.h>
using namespace std;

/*
L   l   r   m
1   0   0   0   0   -1  1   0
2   0   1   0   0   -1   1   1
3   0   2   1   0   0   2   2
*/

string match(const string &a, const string &b, int m){
    int an = a.size();
    int bn = b.size();
    int cvn = bn - m;
    vector<int> fnt(bn, -1), bck(bn, -1);

    int x = 0;
    for(int i = 0; i < an && x < bn; i++){
        if( a[i] == b[x] ){
            fnt[x] = i;
            x++;
        }
    }

    x = bn - 1;
    for(int i = an-1; i >= 0 && x >= 0; i--){
        if( a[i] == b[x] ){
            bck[x] = i;
            x--;
        }
    }
    
    if(cvn == bn) return "";
    for(int i = 0; i < bn; i++){
        int lo = i-1, hi = i+cvn;
        if( lo < 0 ){
            if( bck[hi] != -1 )
                return b.substr(hi, bn - hi);
        }
        else if( hi >= bn ){
            if( fnt[lo] != -1 )
                return b.substr(0, lo+1);
            return "";
        }
        else{
            if( fnt[lo] != -1 && bck[hi] != -1 && fnt[lo] < bck[hi] )
                return b.substr(0, lo+1) + b.substr(hi, bn - hi);
        }
    }
    return "";
}

int main(){
    string a, b;
    cin >> a >> b;
    
    int lo = 1, hi = b.size();
    string res = "-";
    while( lo <= hi ){
        int m = lo + (hi - lo) / 2;
        string tmp = match(a, b, m);
        if(tmp != ""){
            res = tmp;
            lo = m+1;
        }
        else{
            hi = m-1;
        }
    }

    cout << res << endl;
    return 0;
}
