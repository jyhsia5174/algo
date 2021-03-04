typedef long long int lli;
lli m = 10e9+9;
lli p = 31;

lli hash( const string &s ){
    lli res = 0;
    for(int i = 0; i < s; i++){
        res = (res * p + (s[i] - 'a' + 1) ) % m;
    }
    return res;
}
