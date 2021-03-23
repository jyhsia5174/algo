// 2h 20
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> b;

void solve(){
    vector<int> digit(600, 0);
    int head = -1;

    for(int i = 0; i < n; i++){
        int sumi = (i == 0) ? 0 : b[i-1];
        int sumj = b[i];
        for(int j = 0; j < 600; j++){
            if( digit[j] != 9 && sumi < sumj && sumi - digit[j] + 9 * (j+1) >= sumj ){
                do{
                    sumi++;
                    digit[j]++;
                }while( sumi + 9 * j < sumj );

                for(int k = 0; k < j; k++){
                    digit[k] = min(9, sumj - sumi);
                    sumj -= digit[k];
                }

                head = max(head, j);
                break;
            }
            sumi -= digit[j];
        }
        for(int j = head; j >= 0; j--)
            cout << digit[j];
        cout << endl;
    }
}

int main(){
    cin >> n;
    b.resize(n);
    for(auto &v: b)
        cin >> v;

    solve();

    return 0;
}

/*
string helper(string s, int idx, int b){
    if( b == 0 )
        return "";
    
    if( idx == s.size() - 1 ){
        if(s[idx] - '0' < b && b <= 9)
            return to_string(b);
        return "";
    }

    string res = helper(s, idx+1, b - (s[idx]-'0'));
    if( res == "" ){
        int x = s[idx] - '0' + 1;
        int y = b - (s.size()-idx-1)*9;
        x = max(x, y);
        if( x > 9 || x > b )
            return "";
        b -= x;
        while( b > 9 ){
                res += "9";
                b -= 9;
        }
        if( b > 0 ) res += to_string(b);
        while( res.size() < (s.size()-idx-1) )
            res += "0";
        res += to_string(x);
        reverse(res.begin(), res.end());
    }
    else{
        res = s.substr(idx, 1) + res;
    }

    return res;
}

string next(string s, int b){
    string res = helper(s, 0, b);
    if( res != "" ) return res;
    while( b > 9 ){
        res += "9";
        b -= 9;
    }
    if(res.size() < s.size() && b > 1){
        res += to_string(b-1);
        b = 1;
    }
    while( res.size() < s.size() )
        res += "0";
    res += to_string(b);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> B(n);
    for(auto &v: B)
        cin >> v;

    vector<string> A{"0"};
    for(auto b: B){
        A.push_back(next(A.back(), b));
    }

    for(int i = 1; i < A.size(); i++)
        cout << A[i] << endl;
    
    return 0;
}
*/
